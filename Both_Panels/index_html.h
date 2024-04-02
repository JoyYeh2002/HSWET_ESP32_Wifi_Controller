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


  /* NEW STYLE STARTS HEREEEEEE */
  /* Reset some default styles */
* {
  box-sizing: border-box;
  margin: 0;
  padding: 0;
}

body {
  font-family: Arial, sans-serif;
  background-color: #f0f0f0;
}

header {
  max-width: 96vw;
  margin: 0.5rem auto;
  border-radius: 0.5rem;
  background-color: #3498db;
  padding: 8px;
  text-align: center;

  display: grid;
  grid-template-columns: 30% 60%; 
  
  #title {
    color: white;
    margin-top: 4px;
    font-size: 1.3rem;
  }
}

main {
  max-width: 96vw;
  margin: 0.5rem auto;
  display: grid;
  grid-template-columns: 60% 39.5%; 
  gap: 0.5rem;
}

.left-display-box {
    display: grid;
    grid-template-columns: 1fr 1fr;
    gap: 3rem;
}

section {
  background-color: #fff;
  padding: 1rem;
  border-radius: 0.5rem;
  box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
}

.chart-box {
  text-align: center;
}

/* title + data value */
.data-box {
    display: flex;
    justify-content: center; /* Center horizontally */
    align-items: center;
}

.data-box p {
  font-size:18px;
  font-weight: bold;
}
    
.data-value {
    margin-left: 10px; /* Adjust margin as needed */
    color: green;
}

/* Left column bottom right, also used in radio buttons */
.data-display-box {
    display: flex;
    justify-content: center; /* Center horizontally */
    align-items: center;
    background-color: #f9f9f9;
    padding: 2px;
    border-radius: 5px;
    display: grid;
    grid-template-columns: 1fr 1fr;
    box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);

    #title-estop {
    margin-left: 20rem;
    padding-left: 20rem;
    }
}

.data-display-box p {
  font-size:16px;
  font-weight: bold;
}

.radio-group {
  display: flex;
  flex-direction: row;
  gap: 0.5rem;
  margin-top: 0.5rem;
  margin-bottom: 0.5rem;
}

.radio-group input[type="radio"] {
  transform: scale(1.2); /* Increase the size of the radio buttons */
  /* margin-left: 15px; Add some spacing between radio buttons and labels */
}

.radio-display-box {
    display: flex;
    justify-content: center; /* Center horizontally */
    align-items: center;
    background-color: #f9f9f9;
    border-radius: 5px;
    flex: 1;
    gap: 0.5rem;
    
    padding-top: 0.5rem;
    padding-bottom: 0.5rem;
    margin-top: 0.3rem;
    box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
}

/* Hover style for radio buttons */
.radio-display-box:hover {
    background-color: rgb(192, 230, 239);; /* Change to darker gray on hover */
}
  
/* Safety and back-up power on or off */
.toggle-state {
    background-color: #f9f9f9;
    padding: 3px;
    border-radius: 5px;
    box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
    text-align: center;
    color: black;
    background-color: #fac8c8;
}

.chart-container {
  width: 100%;
  height: 22vh;
  background-color: #f0f0f0;
  margin-bottom: 10px;
}

.chart {
  width: 100%;
  height: 100%;
  background-color: #e0e0e0;
}

.controls {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
  gap: 10px;
}

.control-box {
  background-color: #f9f9f9;
  padding: 10px; /* Add padding to the entire control box */
  border-radius: 5px;
  box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
}

.control-box h3{
    margin-bottom: 0.5rem;
}

.input-btn-flex {
    display: flex;
    justify-content: space-between;
    align-items: center;
    width: 100%;
    margin-bottom: 0.5rem;
}

.input-btn-flex > * {
  flex-grow: 0;
  flex-basis: 50%; /* First element takes up 45% */
  max-width: 50%; /* Optional: Set max-width to ensure responsiveness */
}

.input-btn-flex > :nth-child(2),
.input-btn-flex > :nth-child(3) {
  flex-basis: 20%; /* Second and third elements take up 25% each */
  max-width: 25%; /* Optional: Set max-width to ensure responsiveness */
}

.input-btn-flex h3 {
  margin-top: 10px; /* Add some margin to the right of the heading */
}

input[type="text"] {
    height: 35px; /* Set the height to your desired value */
    text-align: center;/* Add any other styling you want for all text input fields */
    width: 6rem;
}

input[type="text"]{
  font-size:16px;
}

.send-btn, .stop-btn, .download-btn {
  background-color: #3498db;
  color: #fff;
  border: none;
  padding: 10px 20px;
  border-radius: 5px;
  cursor: pointer;
  text-align: center;
  transition: background-color 0.3s ease;
  
  display: flex; /* Use flexbox */
  justify-content: center; /* Center horizontally */
  align-items: center; /* Center vertically */
}

.send-btn:hover, .download-btn:hover {
  background-color: #2577ae;
}

.stop-btn {
  padding: 5px 20px;
  background-color: #e74c3c;
}

.stop-btn:hover {
  background-color: #c0392b;
}

.msg {
  color: green;
}

.timestamp {
  display: flex;
  flex-direction: row;
  gap: 2rem;
}

.timestamp p{
  margin-top: 5px;
}

footer {
  background-color: #fff;
  padding: 20px;
  text-align: center;
  box-shadow: 0 -2px 5px rgba(0, 0, 0, 0.1);
  display: flex;
  justify-content: space-around;
  align-items: center;
  flex-wrap: wrap;
}

@media (max-width: 768px) {
  main {
    grid-template-columns: 1fr;
  }

  .controls {
    grid-template-columns: 1fr;
  }
}

/* NEW STYLE ENDS HEREEEEE 
*/

</style>

<!-- NORMAL SENSOR MONITOR -->
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
    <div class="msg" id="date02">mm/dd/yyyy</div> 
    <div class="msg" id="time02">00:00:00</div>
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

  <!-- MY HTML STARTS HERE -->
  <header>
    <div class="data-display-box" id="title-estop">
      <h3>E-Stop Button</h3>
      <p id="safety-state" class="stop-btn">STOP</p>
    </div>
    <h3 id="title">Hopkins Student Wind Energy Team (HWSET) Turbine Control Panel</h3>
  </header>
  <main>
    <!-- Tags: 
    text: 
        wind-speed-value, rpm-value, pwr-value

    charts:
        wind-speed-chart, rpm-chart, pwr-chart
    -->
    <section class="data-charts">
      <div class="chart-box">
        <div class="data-box">
            <h3>Wind Speed: </h3>
            <p id="wind-speed-value" class="data-value">0 m/s</p>
        </div>
        <div class="chart-container">
        <div class="wind-speed-chart"></div>
        </div>
      </div>

      <div class="chart-box">
        <div class="data-box">
            <h3>RPM: </h3>
            <p id="rpm-value" class="data-value">0</p>
        </div>
        <div class="chart-container">
          <div class="rpm-chart"></div>
        </div>
      </div>

      <div class="chart-box">
        <div class="data-box">
            <h3>Output PWR: </h3>
            <p id="pwr-value" class="data-value">0 W</p>
        </div>
        
        <div class="chart-container">
          <div class="pwr-chart"></div> 
        </div>
      </div>

      <!-- Put 2 state displays here -->

      <!-- Tags: 
      text: 
        safety-state, backup-pwr-state
      JS update: 
        toggle-state
      -->

      <div class="left-display-box">
        <div class="data-display-box">
            <h3>Safety State</h3>
            <p id="safety-state" class="toggle-state"> OFF</p>
        </div>

        <div class="data-display-box">
            <h3>Backup PWR</h3>
            <p id="backup-pwr-state" class="toggle-state"> OFF</p>
        </div>
      </div>

    </section>

    <!-- Messages: 
        send-op-mode, send-i-load, send-blade-pitch
        radio-button-msg, load-current-msg, blade-pitch-msg
    -->


    <section class="controls">

      <div class="control-box">
        <div class="input-btn-flex">
            <h3>Operation Mode </h3>
            <button id="send-op-mode" class="send-btn">CONFIGURE</button>
        </div>
        <div class="radio-group">
            <div class="radio-display-box">
                <input type="radio" id="pwr-optimization" name="mode" checked>
                <label for="pwr-optimization">PWR OPTI</label>
            </div>
         
            <div class="radio-display-box">
                <input type="radio" id="durability" name="mode">
                <label for="durability">DURABILITY</label>
            </div>
                
            <div class="radio-display-box">
                <input type="radio" id="rated-pwr" name="mode">
                <label for="rated-pwr">RATED PWR</label>
            </div>
        </div>
        
        <p id="radio-button-msg" class="msg">CONFIG: Choose a mode, then click on "CONFIGURE".</p>
      </div>

      <!-- HHYYYYYYYYYYYYYYYYYYYYYYYYYYY-->
 <div class="control-box">
  <div class="input-btn-flex">
    <h3>Load Current (0 to 2A): </h3>
    <input type="text" id="new-load-value">
    <button id="send-i-load" class="send-btn">SEND</button>
  </div>
  <p id="load-current-msg" class="msg">CONFIG: Please enter load current.</p>
</div>


<div class="control-box">
  <div class="input-btn-flex">
    <h3>Blade Pitch (0 to 5):</h3>
    <input type="text" id="new-blade-pitch" >
    <button id="send-blade-pitch" class="send-btn">SEND</button>
  </div>
  <p id="blade-pitch-msg" class="msg">CONFIG: Please enter blade pitch state.</p>
</div>

    <!-- Time stamp and stuff -->
    <div class="timestamp">
      <p id="date-time" class="msg"></p>
      <p id="test-duration", class="msg">Test Duration: 0 mins, 0 sec</p>
    </div>

    <button class="download-btn">Download Data Report</button>
    <p class="msg">SUCCESS: Data report downloaded at 23:32:41 on 03/31/2024.</p>

    </section>
  </main>

  <!-- Tags: 
    time-stamp, test-duration 
class = msg -->
  <footer>
   <p> Version 1.0.0.</p>
  </footer>

  <footer div class="foot" id="temp">ESP32 Web Page Creation and Data Update Demo </div>
  </footer>
</body>

<script type="text/javascript">

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
    xaxis: { // The top x axis
      type: 'date',
      domain: [0, 1],
      showticklabels: false
    },
    yaxis: { 
      domain: [0.6, 1],
      range: [0, 3.3],
      tickformat: '.2f'
     },
    xaxis2: {
      type: 'date',
      anchor: 'y2',
      domain: [0, 1],
      showticklabels: true,
      tickformat: '%H:%M:%S' 
    },
    yaxis2: {
      anchor: 'x2',
      domain: [0, 0.4],
      range: [0, 3.3],
      tickformat: '.2f'
    },
    title: 'Plotting started at ' + new Date().toLocaleTimeString('en-US')
  }

  // Create the canvas
  var data = [trace1, trace2];
  Plotly.newPlot('myDiv', data, layout, { displayModeBar: false });
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
    document.getElementById("time02").textContent = dt.toLocaleTimeString();
    document.getElementById("date02").textContent = dt.toLocaleDateString();

    formattedTime = dt.toLocaleTimeString();
    formattedDate = dt.toLocaleDateString();
    document.getElementById("date-time").textContent = "Time: " + formattedDate + " " + formattedTime;
    
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
    document.getElementById("wind-speed-value").textContent = msg_V0;

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
    document.getElementById("rpm").innerHTML = msg_B1;

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

    // Plots: Update
    var x_axis_interval = 100;
    var update = {
      x: [[dt], [dt]],
      y: [[msg_V0], [msg_V1]]
    }
    Plotly.extendTraces('myDiv', update, [0, 1], x_axis_interval)

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

  // MY JS STARTS HERE ---------------------------------------
// Button Interactions
document.addEventListener('DOMContentLoaded', function() {
  // Get elements
  const radioButtons = document.querySelectorAll('input[name="mode"]');
  const sendButton = document.getElementById('send-op-mode');
  const radioMsg = document.getElementById('radio-button-msg'); // Updated variable

  // Add event listeners to radio buttons
  radioButtons.forEach(radio => {
      radio.addEventListener('change', function() {
          const selectedRadio = document.querySelector('input[name="mode"]:checked');
          if (selectedRadio) {
              const selectedLabel = selectedRadio.nextElementSibling.textContent;
              // Do not update console message here
          }
      });
  });

  // Add event listener to send button
  sendButton.addEventListener('click', function() {
      const selectedRadio = document.querySelector('input[name="mode"]:checked');
      if (selectedRadio) {
          const selectedLabel = selectedRadio.nextElementSibling.textContent;
          radioMsg.textContent = `SUCCESS: Mode set to "${selectedLabel}".`; // Update console message here
      } else {
          radioMsg.textContent = 'ERROR: Please select a mode.';
      }
  });
});

document.addEventListener('DOMContentLoaded', function() {
  // Get elements
  const newLoadValueInput = document.getElementById('new-load-value');
  const sendButton = document.getElementById('send-i-load');
  const loadCurrentMsg = document.getElementById('load-current-msg');

  let previousValidValue = 0; // Variable to store the previous valid value
  let measuredValue = 0; 

  // Update value when SEND button is clicked
  sendButton.addEventListener('click', function() {
      // Get the new value from the input
      const inputValue = newLoadValueInput.value.trim(); // Remove leading and trailing whitespace
      const decimalCount = (inputValue.match(/\./g) || []).length; // Count the number of decimal points

      if (decimalCount <= 1) {
          // Parse the input value as a float with one decimal point
          const newValue = parseFloat(inputValue).toFixed(1);

          // Check if the parsed value is a valid float between 0 and 2
          if (!isNaN(newValue) && newValue >= 0 && newValue <= 2) {
              // Make pseudorandom number
              const randomFactor = Math.random() * (1.002 - 0.998) + 0.998; // Random number between 0.998 and 1.002
              const measuredValue = newValue * randomFactor;

              // Update the displayed value and success message
        
              loadCurrentMsg.textContent = `SUCCESS: Set to ${newValue} A. Measured ${measuredValue.toFixed(3)} A.`;

              // Save the new value as the previous valid value
              previousValidValue = newValue;

              // Clear the input field
              newLoadValueInput.value = newValue;
          } else {
              // Display error message for out-of-range input
              loadCurrentMsg.textContent = `ERROR: Input out of bounds. Current measured ${measuredValue.toFixed(3)} A.`;

              // Populate the input field with the previous valid value
              newLoadValueInput.value = previousValidValue;
          }
      } else {
          // Display error message for multiple decimal points
          loadCurrentMsg.textContent = 'ERROR: Input must contain only one decimal point.';
      }
  });
});

document.addEventListener('DOMContentLoaded', function() {
  // Get elements
  const newBladePitchInput = document.getElementById('new-blade-pitch');
  const sendBladePitchButton = document.getElementById('send-blade-pitch');
  const bladePitchMsg = document.getElementById('blade-pitch-msg');

  let previousValidPitch = 0; // Variable to store the previous valid pitch

  // Update value when SEND button is clicked
  sendBladePitchButton.addEventListener('click', function() {
    // Get the new pitch value from the input
    const newPitchValue = parseInt(newBladePitchInput.value.trim());

    // Check if the input value is a valid integer between 0 and 5
    if (!isNaN(newPitchValue) && Number.isInteger(newPitchValue) && newPitchValue >= 0 && newPitchValue <= 5) {
      // Update the success message
      bladePitchMsg.textContent = `SUCCESS: Blace pitch state is set to ${newPitchValue}.`;

      // Save the new pitch value as the previous valid value
      previousValidPitch = newPitchValue;

      // Clear the input field
      newBladePitchInput.value = newPitchValue;
    } else {
      // Display error message for invalid input
      bladePitchMsg.textContent = `ERROR: Input out of bounds. Pitch state is ${previousValidPitch}.`;

      // Populate the input field with the previous valid value
      newBladePitchInput.value = previousValidPitch;
    }
  });
});

</script>

</html> )=====";