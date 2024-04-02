const char PAGE_MAIN[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en" class="js-focus-visible">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>HWSET Turbine Control Panel</title>
  <!-- <link rel="stylesheet" type="text/css" href="style.css"> -->
</head>

<style>
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
</style>

<body>
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
            <div class="data-value" id="wind-speed-value"></div>
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
      <p id="time-stamp", class="msg">Time: 03-31-2024 23:32:41</p>
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
</body>
</html>

<script type="text/javascript">

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


  // function to handle the response from the ESP
function response() {

// I want "plot-stream" to update here, so that it can plot a random number every second (when var dt updates)
var msg_B0;

var msg_rpm; // B1
var msg_wind_speed; // V0

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

// wind speed (V0)
xmldoc = xmlResponse.getElementsByTagName("wind-speed"); // V0
msg_wind_speed = xmldoc[0].firstChild.nodeValue;
document.getElementById("wind-speed-value").innerHTML = msg_wind_speed;

// RPM (B1)
xmldoc = xmlResponse.getElementsByTagName("rpm");
msg_rpm = xmldoc[0].firstChild.nodeValue;

// Change colors
if (msg_rpm > 2048) {
  color = "#aa0000";
} else {
  color = "#0000aa";
}
document.getElementById("rpm-value").innerHTML = msg_rpm;
document.getElementById("rpm-value").style.backgroundColor = color;

/*
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
*/
}


function process() {
if (xmlHttp.readyState == 0 || xmlHttp.readyState == 4) {
  xmlHttp.open("PUT", "xml", true);
  xmlHttp.onreadystatechange = response;
  xmlHttp.send(null);
}
setTimeout("process()", 200);
}

</script>

</html> )=====";
