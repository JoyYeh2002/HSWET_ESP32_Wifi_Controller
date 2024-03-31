const char PAGE_MAIN[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en" class="js-focus-visible">

<head>
  <script src="https://cdn.plot.ly/plotly-2.30.1.min.js" charset="utf-8"></script>
</head>

<title>HWSET WIFI Turbine Dashboard</title>

<style>
  table {
    position: relative;
    width: 100%;
    border-spacing: 0px;
  }

  tr {
    border: 1px solid white;
    font-family: "Verdana", "Arial", sans-serif;
    font-size: 20px;
  }

  th {
    height: 20px;
    padding: 3px 15px;
    background-color: #343a40;
    color: #FFFFFF !important;
  }

  td {
    height: 20px;
    padding: 3px 15px;
  }

  .tabledata {
    font-size: 24px;
    position: relative;
    padding-left: 5px;
    padding-top: 5px;
    height: 25px;
    border-radius: 5px;
    color: #FFFFFF;
    line-height: 20px;
    transition: all 200ms ease-in-out;
    background-color: #00AA00;
  }

  .fanrpmslider {
    width: 30%;
    height: 55px;
    outline: none;
    height: 25px;
  }

  .bodytext {
    font-family: "Verdana", "Arial", sans-serif;
    font-size: 24px;
    text-align: left;
    font-weight: light;
    border-radius: 5px;
    display: inline;
  }

  .navbar {
    width: 100%;
    height: 50px;
    margin: 0;
    padding: 10px 0px;
    background-color: #FFF;
    color: #000000;
    border-bottom: 5px solid #293578;
  }

  .fixed-top {
    position: fixed;
    top: 0;
    right: 0;
    left: 0;
    z-index: 1030;
  }

  .navtitle {
    float: left;
    height: 50px;
    font-family: "Verdana", "Arial", sans-serif;
    font-size: 50px;
    font-weight: bold;
    line-height: 50px;
    padding-left: 20px;
  }

  .navheading {
    position: fixed;
    left: 60%;
    height: 50px;
    font-family: "Verdana", "Arial", sans-serif;
    font-size: 20px;
    font-weight: bold;
    line-height: 20px;
    padding-right: 20px;
  }

  .navdata {
    justify-content: flex-end;
    position: fixed;
    left: 70%;
    height: 50px;
    font-family: "Verdana", "Arial", sans-serif;
    font-size: 20px;
    font-weight: bold;
    line-height: 20px;
    padding-right: 20px;
  }

  .category {
    font-family: "Verdana", "Arial", sans-serif;
    font-weight: bold;
    font-size: 32px;
    line-height: 50px;
    padding: 20px 10px 0px 10px;
    color: #000000;
  }

  .heading {
    font-family: "Verdana", "Arial", sans-serif;
    font-weight: normal;
    font-size: 28px;
    text-align: left;
  }

  .btn {
    background-color: #444444;
    border: none;
    color: white;
    padding: 10px 20px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 16px;
    margin: 4px 2px;
    cursor: pointer;
  }

  .foot {
    font-family: "Verdana", "Arial", sans-serif;
    font-size: 20px;
    position: relative;
    height: 30px;
    text-align: center;
    color: #AAAAAA;
    line-height: 20px;
  }

  .container {
    max-width: 1800px;
    margin: 0 auto;
  }

  table tr:first-child th:first-child {
    border-top-left-radius: 5px;
  }

  table tr:first-child th:last-child {
    border-top-right-radius: 5px;
  }

  table tr:last-child td:first-child {
    border-bottom-left-radius: 5px;
  }

  table tr:last-child td:last-child {
    border-bottom-right-radius: 5px;
  }

  /* Additional styles for the real-time plot */
  #realTimePlotContainer {
    width: 80%;
    margin: 0 auto;
    padding-top: 50px;
  }

  #realTimePlotCanvas {
    width: 100%;
    height: 400px;
    /* Adjust height as needed */
  }
</style>

<body style="background-color: #efefef" onload="process()">
  <header>
    <div class="navbar fixed-top">
      <div class="container">
        <div class="navtitle">Sensor Monitor</div>
        <div class="navdata" id="date">mm/dd/yyyy</div>
        <div class="navheading">DATE</div>
        <br>
        <div class="navdata" id="time">00:00:00</div>
        <div class="navheading">TIME</div>
      </div>
    </div>
  </header>

  <main class="container" style="margin-top:70px">
    <div class="category">Turbine Sensor Readings</div>
    <div style="border-radius: 10px !important;">
      <table style="width:50%">
        <colgroup>
          <col span="1" style="background-color:rgb(230,230,230); width: 20%; color:#000000 ;">
          <col span="1" style="background-color:rgb(200,200,200); width: 15%; color:#000000 ;">
          <col span="1" style="background-color:rgb(180,180,180); width: 15%; color:#000000 ;">
        </colgroup>
        <col span="2" style="background-color:rgb(0,0,0); color:#FFFFFF">
        <col span="2" style="background-color:rgb(0,0,0); color:#FFFFFF">
        <col span="2" style="background-color:rgb(0,0,0); color:#FFFFFF">
        <tr>
          <th colspan="1">
            <div class="heading">Pin</div>
          </th>
          <th colspan="1">
            <div class="heading">Bits</div>
          </th>
          <th colspan="1">
            <div class="heading">Volts</div>
          </th>
        </tr>
        <tr>
          <td>
            <div class="bodytext">A0: Analog pin 10</div>
          </td>
          <td>
            <div class="tabledata" id="b0"></div>
          </td>
          <td>
            <div class="tabledata" id="v0"></div>
          </td>
        </tr>
        <tr>
          <td>
            <div class="bodytext">A1: Analog pin 17</div>
          </td>
          <td>
            <div class="tabledata" id="b1"></div>
          </td>
          <td>
            <div class="tabledata" id="v1"></div>
          </td>
        </tr>
        <tr>
          <td>
            <div class="bodytext">Digital switch</div>
          </td>
          <td>
            <div class="tabledata" id="switch"></div>
          </td>
        </tr>
      </table>
    </div>
    <br>

    <div class="category">Subplots: Streaming</div>
    <div id="myDiv"></div>
    <button type="button" class="btn" id="downloadTraces" onclick="downloadTracesAsCSV()">Download Plots to CSV</button>

    <div class="category">Sensor Controls</div>
    <br>
    <div class="bodytext">LED </div>
    <button type="button" class="btn" id="btn0" onclick="ButtonPress0()">Toggle</button>
    </div>
    <br>
    <div class="bodytext">Switch</div>
    <button type="button" class="btn" id="btn1" onclick="ButtonPress1()">Toggle</button>
    </div>
    <br>
    <br>
    <div class="bodytext">Fan Speed Control (RPM: <span id="fanrpm"></span>) </div>
    <br>
    <input type="range" class="fanrpmslider" min="0" max="255" value="0" width="0%"
      oninput="UpdateSlider(this.value)" />
    <br>
    <br>
  </main>

  <footer div class="foot" id="temp">ESP32 Web Page Creation and Data Update Demo </div>
  </footer>
</body>

<script type="text/javascript">


  /*
  function rand() {
    return Math.random();
  }
  
  var time = new Date();
  var data = [{
    x: [time],
    y: [rand()],
    mode: 'lines',
    line: {color: '#80CAF6'}
  }]

  Plotly.newPlot('plot-stream', data); */

  // --------------------------------------------
  function rand() {
    return Math.random();
  }

  var time = new Date();

  // Define 2 traces
  var trace1 = {
    x: [],
    y: [],
    mode: 'lines',
    line: {
      color: '#80CAF6',
      shape: 'spline'
    },
    name: 'A0 Voltage'
  }

  var trace2 = {
    x: [],
    y: [],
    xaxis: 'x2',
    yaxis: 'y2',
    mode: 'lines',
    line: { color: '#DF56F1' },
    name: 'A1 Voltage'
  };

  // Make sub-plot layout
  var layout = {
    xaxis: {
      type: 'date',
      domain: [0, 1],
      showticklabels: false
    },
    yaxis: { domain: [0.6, 1] },
    xaxis2: {
      type: 'date',
      anchor: 'y2',
      domain: [0, 1]
    },
    yaxis2: {
      anchor: 'x2',
      domain: [0, 0.4]
    },
  }

  // Create the canvas
  var data = [trace1, trace2];
  Plotly.newPlot('myDiv', data, layout, {displayModeBar: false});
  // --------------------------------------------

  var cnt = 0;

  // global variable visible to all java functions
  var xmlHttp = createXmlHttpObject();

  // function to create XML object
  function createXmlHttpObject() {
    if (window.XMLHttpRequest) {
      xmlHttp = new XMLHttpRequest();
    } else {
      xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
    }
    return xmlHttp;
  }

  // global variable to hold URL to file to be downloaded (see generateCSVUrl())
  let csvFileUrl = null;

  // Function for generating a text file URL containing given text
  function generateCSVUrl(txt) {
      let fileData = new Blob([txt], {type: 'text/csv'});
      // If a file has been previously generated, revoke the existing URL
      if (csvFileUrl !== null) {
          window.URL.revokeObjectURL(textFile);
      }
      csvFileUrl = window.URL.createObjectURL(fileData);
      // Returns a reference to the global variable holding the URL
      // Again, this is better than generating and returning the URL itself from the function as it will eat memory if the file contents are large or regularly changing
      return csvFileUrl;
  };

  // Function for downloading file from URI
  function downloadURI(uri, name) {
    let link = document.createElement("a");
    link.download = name;
    link.href = uri;
    document.body.appendChild(link);
    link.click();
    document.body.removeChild(link);
    delete link;
  }

  function ButtonPress0() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("PUT", "BUTTON_0", false);
    xhttp.send();
  }

  function ButtonPress1() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("PUT", "BUTTON_1", false);
    xhttp.send();
  }

  function UpdateSlider(value) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
      if (this.readyState == 4 && this.status == 200) {
        // update the web based on reply from  ESP
        document.getElementById("fanrpm").innerHTML = this.responseText;
      }
    }
    xhttp.open("PUT", "UPDATE_SLIDER?VALUE=" + value, true);
    xhttp.send();
  }

  // function to handle the response from the ESP
  function response() {

    // I want "plot-stream" to update here, so that it can plot a random number every second (when var dt updates)
    var msg_B0;
    var msg_B1;
    var msg_V0;
    var msg_V1;

    var msg;

    var barwidth;
    var currentsensor;
    var xmlResponse;
    var xmldoc;
    var dt = new Date();
    var color = "#e8e8e8";

    // get the xml stream
    xmlResponse = xmlHttp.responseXML;

    // get host date and time
    document.getElementById("time").innerHTML = dt.toLocaleTimeString();
    document.getElementById("date").innerHTML = dt.toLocaleDateString();

    // B0
    xmldoc = xmlResponse.getElementsByTagName("B0"); //bits for A0
    msg_B0 = xmldoc[0].firstChild.nodeValue;
    if (msg_B0 > 2048) {
      color = "#aa0000";
    } else {
      color = "#0000aa";
    }
    barwidth = msg_B0 / 40.95;
    document.getElementById("b0").innerHTML = msg_B0;
    document.getElementById("b0").style.width = (barwidth + "%");

    // V0
    xmldoc = xmlResponse.getElementsByTagName("V0"); //volts for A0
    msg_V0 = xmldoc[0].firstChild.nodeValue;
    document.getElementById("v0").innerHTML = msg_V0;
    document.getElementById("v0").style.width = (barwidth + "%");
    document.getElementById("v0").style.backgroundColor = color;

    // B1
    xmldoc = xmlResponse.getElementsByTagName("B1");
    msg_B1 = xmldoc[0].firstChild.nodeValue;
    if (msg_B1 > 2048) {
      color = "#aa0000";
    } else {
      color = "#0000aa";
    }
    document.getElementById("b1").innerHTML = msg_B1;
    width = msg_B1 / 40.95;
    document.getElementById("b1").style.width = (width + "%");
    document.getElementById("b1").style.backgroundColor = color;

    // V1
    xmldoc = xmlResponse.getElementsByTagName("V1");
    msg_V1 = xmldoc[0].firstChild.nodeValue;
    document.getElementById("v1").innerHTML = msg_V1;
    document.getElementById("v1").style.width = (width + "%");
    document.getElementById("v1").style.backgroundColor = color;

    xmldoc = xmlResponse.getElementsByTagName("LED");
    msg = xmldoc[0].firstChild.nodeValue;
    if (msg == 0) {
      document.getElementById("btn0").innerHTML = "Turn ON";
    } else {
      document.getElementById("btn0").innerHTML = "Turn OFF";
    }
    xmldoc = xmlResponse.getElementsByTagName("SWITCH");
    msg = xmldoc[0].firstChild.nodeValue;
    document.getElementById("switch").style.backgroundColor = "rgb(200,200,200)";

    // Update the subplots
    var update = {
      x: [[dt], [dt]],
      y: [[msg_V0], [msg_V1]]
    }
    Plotly.extendTraces('myDiv', update, [0, 1])

    // update the text in the table
    if (msg == 0) {
      document.getElementById("switch").innerHTML = "Switch is OFF";
      document.getElementById("btn1").innerHTML = "Turn ON";
      document.getElementById("switch").style.color = "#0000AA";
    } else {
      document.getElementById("switch").innerHTML = "Switch is ON";
      document.getElementById("btn1").innerHTML = "Turn OFF";
      document.getElementById("switch").style.color = "#00AA00";
    }

  }

  function process() {
    if (xmlHttp.readyState == 0 || xmlHttp.readyState == 4) {
      xmlHttp.open("PUT", "xml", true);
      xmlHttp.onreadystatechange = response;
      xmlHttp.send(null);
    }
    setTimeout("process()", 200);
  }

  function downloadTracesAsCSV() {
    // trace1.y & trace2.x/y should all be the same length
    let today = new Date();
    let csvData = `
    HSWET Turbine Dashboard Download,${today}\n
    Trace1: ${trace1.name},, Trace2: ${trace2.name},\n
    trace1.x, trace1.y, trace2.x, trace2.y`;
    for (let i = 0; i < trace1.x.length; i++) {
      let x1 = trace1.x[i].toLocaleTimeString()
      let x2 = trace2.x[i].toLocaleTimeString()

      csvData += `\n${x1}, ${trace1.y[i]}, ${x2}, ${trace2.y[i]}`;
    }
    let url = generateCSVUrl(csvData)

    downloadURI(url, "data.csv");
  }


</script>

</html> )=====";