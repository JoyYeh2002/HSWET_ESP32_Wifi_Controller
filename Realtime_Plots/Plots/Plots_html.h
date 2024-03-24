const char PAGE_MAIN[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en" class="js-focus-visible">
  <title>HWSET Real Time Plotting with Web Server</title>

  <head>
    <script src="https://cdn.plot.ly/plotly-2.30.1.min.js" charset="utf-8"></script>
</head>

  
  <body style="background-color: #efefef" onload="process()">
    <main class="container" style="margin-top:70px">
      <div class="category">Turbine Sensor Readings</div>

      <div id="gd"></div>

      <div style="border-radius: 10px !important;">
        <table style="width:50%">
          <colgroup>
            <col span="1" style="background-color:rgb(230,230,230); width: 20%; color:#000000 ;">
            <col span="1" style="background-color:rgb(200,200,200); width: 15%; color:#000000 ;">
          
          </colgroup>
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
              <div class="bodytext">Analog pin 10</div>
            </td>
            <td>
              <div class="tabledata" id="b0"></div>
            </td>
            <td>
              <div class="tabledata" id="v0"></div>
            </td>
          </tr>
          
        </table>


      </div>

      

    </main>
  </body>
  
  <script type="text/javascript">
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
      var message;
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

      // A0
      xmldoc = xmlResponse.getElementsByTagName("B0"); //bits for A0
      message = xmldoc[0].firstChild.nodeValue;
      if (message > 2048) {
        color = "#aa0000";
      } else {
        color = "#0000aa";
      }

      barwidth = message / 40.95;
      document.getElementById("b0").innerHTML = message;
      document.getElementById("b0").style.width = (barwidth + "%");
      
      xmldoc = xmlResponse.getElementsByTagName("V0"); //volts for A0
      message = xmldoc[0].firstChild.nodeValue;

    Plotly.plot('chart',[{
              y:[message],
              type:'line'
          }]);

    var cnt = 0;
    serInterval(function(){
      Plotly.extendTraces('chart',{ y:[[getData()]]}, [0]);
      cnt++;
      if(cnt > 500) {
        Plotly.relayout('chart', {
          xaxis: {
            range: [cnt-500,cnt]
          }
        });
      }
    }, 15);
    
      
      document.getElementById("v0").innerHTML = message;
      document.getElementById("v0").style.width = (barwidth + "%");
      document.getElementById("v0").style.backgroundColor = color;
      
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