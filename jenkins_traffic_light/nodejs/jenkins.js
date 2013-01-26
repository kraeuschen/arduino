var dgram        = require("dgram")
    , server     = dgram.createSocket("udp4")
    , SerialPort = require("serialport").SerialPort
    , status     = ''
    , readData   = '';

var serialPort = new SerialPort("/dev/ttyACM0", {
     baudrate: 9600
   , databits: 8
   , parity: 'none'
   , stopbits: 1
   , flowControl: false
});

server.on("message", function (msg) {

    var jenkins = JSON.parse(msg);

    switch(jenkins.build.phase)
    {
        case "STARTED":
            status = "b";
            break;
        case "FINISHED":
            if (jenkins.build.status == "SUCCESS") {
                status = "s";
            } else if (jenkins.build.status == "FAILURE") {
                status = "f";
            } else {
                status = "o";
            }
            break;
        default:
            return;
    }

    serialPort.write(status);
});

server.bind(43278);

serialPort.on("open", function () {
    serialPort.on('data', function(data) {
        readData += data.toString();

        if (readData.indexOf('READY') >= 0) {
            readData = '';
            // resets last state, if script died and the led still shining
            serialPort.write("o");
        }
    });
});

