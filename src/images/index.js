// @ts-nocheck

'use strict'

// https://github.com/Mikhus/canvas-gauges
var rpmpauge = new RadialGauge({
    renderTo: 'gauge-radial-1',
    highlights: [
        { "from": 0, "to": 25, "color": "rgba(0,255,0)" },
        { "from": 25, "to": 30, "color": "rgba(255,0,0)" }
    ],
    width: 300,
    height: 300,
    units: "RPM/100",
    minValue: 0,
    maxValue: 30,
    majorTicks: [0,5,10,15,20,25,30],
    minorTicks: 10,
    strokeTicks: true,
    colorPlate: "#fff",
    borderShadowWidth: 0,
    borders: false,
    needle: false,
    needleType: "arrow",
    needleWidth: 2,
    needleCircleSize: 0,
    needlCircleOuter: false,
    needleCircleInner: false,
    animationDuration: 1500,
    animationRule: "linear",
    valueBox: false,
    valueInt: 2,
    valueDec: 2,
    fontNumbersSize:38,
}).draw()
// var gauge = new LinearGauge({
//     renderTo: 'gauge-radial-1'
// }).draw()

// Listen for incoming messages from Node-RED
uibuilder.onChange('msg', function(msg) {
    // Dump the msg as text to the "msg" html element
    const eMsg = $('#msg')
    if (eMsg) eMsg.innerHTML = uibuilder.syntaxHighlight(msg)

    gauge.value = msg.payload
    gauge.update({
        title: msg.topic
    })
})


function download() {
    var download = document.getElementById("download");
    var image = document.getElementById("gauge-radial-1").toDataURL("image/png")
        .replace("image/png", "image/octet-stream");
    download.setAttribute("href", image);
}