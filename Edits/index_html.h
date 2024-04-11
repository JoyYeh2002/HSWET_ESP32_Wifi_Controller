const char PAGE_MAIN[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en" class="js-focus-visible">

<head>
  <script src="https://cdn.plot.ly/plotly-2.30.1.min.js" charset="utf-8"></script>
</head>

<title>HWSET WIFI Turbine Dashboard</title>

<style>

* {
  box-sizing: border-box;
  margin: 0;
  padding: 0;
}

body {
  font-family: Arial, sans-serif;
  background-color: #f0f0f0;
}

h3 {
  font-size: 1.05rem;
}

header {
  max-width: 96vw;
  margin: 0.5rem auto;
  border-radius: 0.5rem;
  background-color: #3498db;
  padding: 8px;
  text-align: center;

  display: grid;
  grid-template-columns: 25% 65%; 
  
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

.charts-and-titles {
    display: grid;
    grid-template-columns: 73% 25%;
    column-gap: 2%;
    height: 78vh; /* 70% of viewport height */
    margin-bottom: 1rem;
}

.chart-box {
    width: 100%;
    height: 100%;
    background-color: #f0f0f0;
    border-radius: 10px;
    box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
    grid-column: 1; /* Place in the first column (60%) */
    
}

.chart-text-column {
    display: flex;
    flex-direction: column;
    justify-content: space-between;
    height: 100%;
    grid-column: 2; /* Place in the first column (60%) */
}


    
    .chart-textbox {
      display: flex;
      flex-direction: column;
      justify-content: center;
      align-items: center;
      height: calc(30% - 10px); /* 33% of the height with spacing */
      border-radius: 10px;
      box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
    }

    .chart-textbox h3,
    .chart-textbox p {
      margin: 0;
      text-align: center;
    }

    .chart-textbox h3 {
      font-size: 1rem;
      margin-bottom: 0.5rem;
    }
    
    .chart-textbox p {
      font-size: 2rem;
      font-weight: bold;
    }


.chart{
  width: 100%;
  height: 100%; /* Use 100% height to fill the parent container */
}

/* title + data value */
.data-box {
    display: flex;
    justify-content: center; /* Center horizontally */
    align-items: center;
}

.data-box p {
  font-size:1rem;
  font-weight: bold;
}
    
.data-value {
  margin-left: 10px; /* Adjust margin as needed */
}

/* Left column bottom right, also used in radio buttons */
.data-display-box {
  
    justify-content: center; /* Center horizontally */
    align-items: center;
    background-color: #f9f9f9;
    padding: 2px;
    border-radius: 5px;
    display: grid;
    grid-template-columns: 1fr 1fr;
    box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
}

.stop-display-box {
  display: grid;
  grid-template-columns: 65% 35%;
  align-items: center;
  background-color: #f9f9f9;
  justify-content: center;
  box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
  border-radius: 5px;
  padding: 5px;
}

.stop-display-box h3 {
  grid-column: 1;
}

.stop-display-box button {
  grid-column: 2;
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
  background-color: rgb(192, 230, 239); /* Change to darker gray on hover */
}

.radio-display-box input[type="radio"]:checked {
  background-color: red; /* Change to red when selected */
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

.chart {
  width: 100%;
  height: 100%; /* Fill the entire height of the chart container */
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
    font-size: 1.05rem;
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
    font-size:16px;
}

.send-btn, .stop-btn, .download-btn {
  background-color: #3498db;
  font-weight: bold;
  color: #fff;
  border: none;
  padding: 10px 20px;
  border-radius: 5px;
  cursor: pointer;
  text-align: center;
  transition: background-color 0.4s ease;
  
  display: flex; /* Use flexbox */
  justify-content: center; /* Center horizontally */
  align-items: center; /* Center vertically */
}


.stop-btn {
  padding: 5px 10px;
  background-color: #e74c3c;
}

.stop-btn:hover {
  background-color: #c0392b;
}

.send-btn:hover, .download-btn:hover {
  background-color: #2577ae;
}

.download-btn {
  padding: 5px 3.5px;
  background-color:#3498db;
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



</style>

<!-- NORMAL SENSOR MONITOR -->
<body style="background-color: #efefef" onload="process()">

  <!-- MY HTML STARTS HERE -->
  <header>
    <div class="stop-display-box" id="title-estop">
      <h3>EMERGENCY STOP</h3>
      <button type="button" class="stop-btn" id="btn0" onclick="ButtonPress0()">STOP</button>
    </div>

    <div class="stop-display-box" id="title-estop">
      <h3>START EXPERIMENT</h3>
      <button type="button" class="stop-btn" id="btn1" onclick="ButtonPress1()">RUN TRIAL</button>
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

      <div class="charts-and-titles">
        <!-- charts on left column -->
        <div class="chart-box">
            <div id="charts" class="chart"></div>
        </div>

        <!-- tags on right column -->
        <div class="chart-text-column">
          <div class="chart-textbox">
            <h3>WIND SPEED </h3>
            <p id="wind-speed-value" class="data-value">0 m/s</p>
          </div>
          
          <div class="chart-textbox">
            <h3>RPM </h3>
            <p id="rpm-value" class="data-value">0</p>
          </div>
        
          <div class="chart-textbox">
            <h3>POWER </h3>
            <p id="pwr-value" class="data-value">0 W</p>
          </div>
        </div>
      </div>
   
      <div class="left-display-box">
        <div class="data-display-box">
            <h3>SAFETY STATE</h3>
            <p id="safety" class="toggle-state"> OFF</p>
        </div>

        <div class="data-display-box">
            <h3>BACKUP PWR</h3>
            <p id="backup-pwr" class="toggle-state"> OFF</p>
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
            <h3>OPERATION MODE </h3>
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
    <h3>LOAD CURRENT (0 to 2A): </h3>
    <input type="text" id="new-load-value">
    <button id="send-i-load" class="send-btn">SEND</button>
  </div>
  <p id="load-current-msg" class="msg">CONFIG: Please enter load current.</p>
</div>

<div class="control-box">
  <div class="input-btn-flex">
    <h3>BLADE PITCH (0 to 5):</h3>
    <input type="text" id="new-blade-pitch" >
    <button id="send-blade-pitch" class="send-btn">SEND</button>
  </div>
  <p id="blade-pitch-msg" class="msg">CONFIG: Please enter blade pitch state.</p>
</div>

    <!-- Time stamp and download button -->
    <div class="timestamp">
      <p id="date-time" class="msg">MM-DD-YYYY</p>
      <p id="test-duration", class="msg">Test Duration: 0 mins, 0 sec</p>
    </div>

    <button type="button" class="download-btn" id="downloadTraces" onclick="downloadTracesAsCSV()">DOWNLOAD DATA CSV</button>

    <p class="msg" id="download-msg">Press the button to download experiment results.</p>

    </section>
  </main>
</body>

<script type="text/javascript">

  // --------------------------------------------
  function rand() {
    return Math.random();
  }

  var time = new Date();
  
  var trace1 = { 
    name: 'Wind Speed (m/s)',
    x: [],
    y: [],
    mode: 'lines',
    line: {
      color: '#80CAF6',
      shape: 'spline'
    },
    showlegend: false
  }
  
  var trace2 = {
    name: 'RPM',
    x: [],
    y: [],
    xaxis: 'x2',
    yaxis: 'y2',
    mode: 'lines',
    line: {color: '#DF56F1'},
    showlegend: false
  };
  
  var trace3 = {
    name: 'Power (w)',
    x: [],
    y: [],
    xaxis: 'x3',
    yaxis: 'y3',
    mode: 'lines',
    line: {color: '#9a9a9a'},
    showlegend: false
  };
  

  var vw = window.innerWidth * 0.40;
  var vh = 500; // put 3 plots together

  // Define scaling constant for subplot height and spacing
  var plotHeight = 0.22; // Adjust for desired subplot height (0 to 1)
  var plotSpacing = 0.11; 

  var layout = {
    width: vw,
    height: vh,
    margin: {
    t: 0,  // top margin
    b: 40, // bottom margin
    l: 35, // left margin
    r: 10  // right margin
    },

    xaxis: { // WIND SPEED
      type: 'date', 
      tickformat: '%H:%M:%S', 
      tickmode: 'linear', 
      tick0: new Date().getTime(), 
      dtick: 5000, 
      showticklabels: true, 
      domain: [0, 1],
	  showticklabels: false
    },
    yaxis: {
      domain: [plotHeight * 2 + plotSpacing * 2, plotHeight * 3 + plotSpacing * 2], // 0.5, 0.7
      range: [0, 12],
      tickformat: '.2f',
      tickmode: 'array',
      tickvals: [0, 4, 8, 12]
    },

    xaxis2: { // RPM
      type: 'date', 
      anchor: 'y2', 
      tickformat: '%H:%M:%S', 
      tickmode: 'linear', 
      tick0: new Date().getTime(), 
      dtick: 5000, 
      showticklabels: true, 
      domain: [0, 1],
	  showticklabels: false

    },
    yaxis2: {
      anchor: 'x2', 
      domain: [plotHeight + plotSpacing, plotHeight * 2 + plotSpacing], //0.25, 0.45 P2
      range: [0, 2000],
      tickmode: 'array',
      tickvals: [0, 500, 1000, 1500, 2000]
    },

    xaxis3: { // PWR
      type: 'date', 
      anchor: 'y3', 
      tickformat: '%H:%M:%S', 
      tickmode: 'linear', 
      tick0: new Date().getTime(), 
      dtick: 5000, 
      showticklabels: true, 
      domain: [0, 1]
    },
    yaxis3: {
      anchor: 'x3', 
      domain: [0, plotHeight],
      range: [0, 20],
      tickmode: 'array',
      tickvals: [0, 4, 8, 12, 16, 20]
    }
  }

  var data = [trace1,trace2,trace3]; 
  Plotly.newPlot('charts', data, layout, { displayModeBar: false });
  
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

  // ----------------- DOWNLOAD BUTTON -------------------
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

  // -----------------------------------------------------

  // BUTTON_STOP (BUTTON_0) 
  function ButtonPress0() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("PUT", "BUTTON_STOP", false);
    xhttp.send();
  }

  // BUTTON_RUN (BUTTON_1) 
  function ButtonPress1() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("PUT", "BUTTON_RUN", false);
    xhttp.send();
  }

  function SetOperationMode(mode_str) {
    var xhttp = new XMLHttpRequest();
    
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        // update the web based on reply from ESP
        radioMsg.textContent = `SUCCESS: Mode set to "${mode_str}".`; 
      }
    }
  
    if (mode_str == "PWR OPTI") {
      xhttp.open("PUT", "PWR_OPTI", true); 
      xhttp.send();
    } else if (mode_str == "DURABILITY") {
        xhttp.open("PUT", "DURABILITY", true); 
        xhttp.send();
    } else if (mode_str == "RATED PWR") {
        xhttp.open("PUT", "RATED_PWR", true); 
        xhttp.send();
    } else {
        radioMsg.textContent = 'ERROR: Invalid mode selected.'; 
        return;
    }
  }


  // function to handle the response from the ESP
  function response() {

    // I want "plot-stream" to update here, so that it can plot a random number every second (when var dt updates)
    var msg_B1;
    var msg_V0;
    var msg_V1;

    var msg; // stop light

    var barwidth;
    var currentsensor;
    var xmlResponse;
    var xmldoc;
    var dt = new Date();
    var color = "#e8e8e8";

    // get the xml stream
    xmlResponse = xmlHttp.responseXML;

    // get host date and time
    formattedTime = dt.toLocaleTimeString();
    formattedDate = dt.toLocaleDateString();
    document.getElementById("date-time").textContent = "Time: " + formattedDate + " " + formattedTime;
    
    // V0
    xmldoc = xmlResponse.getElementsByTagName("wind-speed");  
    msg_V0 = xmldoc[0].firstChild.nodeValue;

    if (msg_V0 > 0.5) {
      color = "#aa0000";
    } else {
      color = "#0000aa";
    }

    document.getElementById("wind-speed-value").textContent = msg_V0 + " m/s";
    document.getElementById("wind-speed-value").style.color = color;
    
    // B1
    xmldoc = xmlResponse.getElementsByTagName("rpm");
    msg_B1 = xmldoc[0].firstChild.nodeValue;

    document.getElementById("rpm-value").textContent = msg_B1;
    document.getElementById("rpm-value").style.color = color;

    // V1
    xmldoc = xmlResponse.getElementsByTagName("pwr");
    msg_V1 = xmldoc[0].firstChild.nodeValue;
    document.getElementById("pwr-value").textContent = msg_V1 + " W";
    document.getElementById("pwr-value").style.color = color;


    // Toggle stop button on pin 13
    xmldoc = xmlResponse.getElementsByTagName("STOP");
    msg = xmldoc[0].firstChild.nodeValue;
    if (msg == 0) {
      document.getElementById("btn0").textContent = "STOP";
      document.getElementById("btn0").style.backgroundColor = "#a2a2a2";
    } else {
      document.getElementById("btn0").textContent = "STOPPED";
      document.getElementById("btn0").style.backgroundColor = "#e74c3c";
    }

    // Toggle exp run button on pin 21
    xmldoc = xmlResponse.getElementsByTagName("RUN");
    msg = xmldoc[0].firstChild.nodeValue;
    if (msg == 0) { // not running
      document.getElementById("btn1").textContent = "EXP STAND BY";
      document.getElementById("btn1").style.backgroundColor = "#a2a2a2";
    } else { // running
      document.getElementById("btn1").textContent = "EXP RUNNING";
      document.getElementById("btn1").style.backgroundColor = "#3df5aa";
    }

    // Toggle safety state box on pin 45
    xmldoc = xmlResponse.getElementsByTagName("SATEFY");
    msg = xmldoc[0].firstChild.nodeValue;
    if (msg == 0) { // not running
      document.getElementById("safety").textContent = "OFF";
      document.getElementById("safety").style.backgroundColor = "#f2f2f2";
    } else { // running
      document.getElementById("safety").textContent = "ON";
      document.getElementById("safety").style.backgroundColor = "#e74c3c";
    }

    // Toggle backup power state box on pin 46
    xmldoc = xmlResponse.getElementsByTagName("BACKUP");
    msg = xmldoc[0].firstChild.nodeValue;
    if (msg == 0) { // not running
      document.getElementById("backup-pwr").textContent = "OFF";
      document.getElementById("backup-pwr").style.backgroundColor = "#f2f2f2";
    } else { // running
      document.getElementById("backup-pwr").textContent = "ON";
      document.getElementById("backup-pwr").style.backgroundColor = "#e74c3c";
    }

    // Plots: Update
    var x_axis_interval = 50;
    var update = {
      x: [[dt], [dt], [dt]],
      y: [[msg_V0], [msg_B1], [msg_V1]]
    }
    
    Plotly.extendTraces('charts', update, [0,1,2], x_axis_interval)
   
    // update the text in the table
    // if (msg == 0) {
    //   document.getElementById("btn1").innerHTML = "Turn ON";
    // } else {
    //   document.getElementById("btn1").innerHTML = "Turn OFF";
    // }
  }

  function process() {
    if (xmlHttp.readyState == 0 || xmlHttp.readyState == 4) {
      xmlHttp.open("PUT", "xml", true);
      xmlHttp.onreadystatechange = response;
      xmlHttp.send(null);
    }
    setTimeout("process()", 400);
  }

// -------------------- DOWNLOAD REPORT FORMATTING ---------------
  function downloadTracesAsCSV() {
    // trace1.y & trace2.x/y should all be the same length
    let today = new Date();
    let csvData = `HSWET Turbine Dashboard Download,\n${today}\n
    Time, ${trace1.name}, ${trace2.name}, ${trace3.name}\n`;
    for (let i = 0; i < trace1.x.length; i++) {
      let x1 = trace1.x[i].toLocaleTimeString('en-US')
     
      csvData += `\n${x1}, ${trace1.y[i]}, ${trace2.y[i]}, ${trace3.y[i]}`;
    }
    let url = generateCSVUrl(csvData)

    const dt = new Date();  // Create a date time object (replace with your actual object if needed)

    const year = dt.getFullYear();
    const month = String(dt.getMonth() + 1).padStart(2, "0"); // Month (0-indexed)
    const day = String(dt.getDate()).padStart(2, "0");  // Day

    const hours = String(dt.getHours()).padStart(2, "0");
    const minutes = String(dt.getMinutes()).padStart(2, "0");

    const formattedDateTime = `${month}_${day}_${year}_${hours}_${minutes}`;



    downloadURI(url, formattedDateTime + "_turbine_data.csv");

    document.getElementById("download-msg").textContent = "SUCCESS: Downloaded data CSV at " + formattedTime;
  }

  // -------------------------------------------------------------

  // MY JS STARTS HERE ---------------------------------------
// Button Interactions

const radioMsg = document.getElementById('radio-button-msg'); // Define radioMsg globally

document.addEventListener('DOMContentLoaded', function() {
  // Get elements
  const radioButtons = document.querySelectorAll('input[name="mode"]');
  const sendButton = document.getElementById('send-op-mode');
 // const radioMsg = document.getElementById('radio-button-msg'); // Updated variable

 // Add event listeners to radio buttons
 radioButtons.forEach(radio => {
      radio.addEventListener('change', function() {
          const selectedRadio = document.querySelector('input[name="mode"]:checked');
          // Reset color of any previously selected label
          
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
          SetOperationMode(selectedLabel);
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