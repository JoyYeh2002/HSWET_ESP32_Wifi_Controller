const char PAGE_MAIN[] PROGMEM = R"=====(
<html lang="en" class="js-focus-visible">
  <head>
    <meta http-equiv='refresh' content='5' />
    <title>HWSET Wind Turbine Control Panel</title>
    <style>
      body { background-color: #e6fffa; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }
    </style>
  </head>

  <body>
    <header>
      <div class="navbar fixed-top">
         <div class="container">
            <div class="navtitle">Sensor Monitor</div>
            <div class="navdata" id = "date">mm/dd/yyyy</div>
            <div class="navheading">DATE</div><br>
            <div class="navdata" id = "time">00:00:00</div>
            <div class="navheading">TIME</div>
          </div>
      </div>
    </header>

    <h1>HWSET Wind Turbine Control Panel</h1>
    <p>Uptime: %02d:%02d:%02d</p>
    <img src="/test.svg" />
  </body>

  <script type = "text/javascript">

    var xmlHttp=createXmlHttpObject();

    // function to create XML object
    function createXmlHttpObject(){
      if(window.XMLHttpRequest){
        xmlHttp=new XMLHttpRequest();
      }
      else{
        xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
      }
      return xmlHttp;
    }

    function response(){
      var message;
      var barwidth;
      var currentsensor;
      var xmlResponse;
      var xmldoc;
      var dt = new Date();
      var color = "#e8e8e8";
     
      // get the xml stream
      xmlResponse=xmlHttp.responseXML;
  
      // get host date and time
      document.getElementById("time").innerHTML = dt.toLocaleTimeString();
      document.getElementById("date").innerHTML = dt.toLocaleDateString();
    }


    function process(){
      if(xmlHttp.readyState==0 || xmlHttp.readyState==4) {
        xmlHttp.open("PUT","xml",true);
        xmlHttp.onreadystatechange=response;
        xmlHttp.send(null);
      }       
        // you may have to play with this value, big pages need more porcessing time, and hence
        // a longer timeout
        setTimeout("process()",250);
    }
  </script>
</html>)=====";