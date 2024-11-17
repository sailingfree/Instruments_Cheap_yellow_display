// @ts-nocheck

'use strict'

// https://github.com/Mikhus/canvas-gauges
var rpmpauge = new RadialGauge({
    renderTo: 'windgauge',
    highlights: [
        { "from": 0, "to": 30, "color": "rgba(255,0,0)" },
        { "from": 30, "to": 330, "color": "rgba(0,255,0)" },
        { "from": 330, "to": 360, "color": "rgba(255,0,0)" },
    ],
    width: 160,
    height: 160,
    units: "App Wind",
    minValue: 0,
    maxValue: 360,
    majorTicks: [0,30,60,90,120,150,180,150,120,90,60,30,0],
    minorTicks: 3,
    ticksAngle: 360,
    startAngle: 180,
    strokeTicks: false,
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
    fontNumbersSize:28,
    fontNumbersWeight: "bold",
    numbersMargin: -12,
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
    var image = document.getElementById("windgauge").toDataURL("image/png")
        .replace("image/png", "image/octet-stream");
    download.setAttribute("href", image);
}