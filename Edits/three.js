function rand() {
    return Math.random();
  }
  
  var time = new Date();
  
  var trace1 = {
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
    x: [],
    y: [],
    xaxis: 'x2',
    yaxis: 'y2',
    mode: 'lines',
    line: {color: '#DF56F1'},
	 showlegend: false 
  };
  
  var trace3 = {
    x: [],
    y: [],
    xaxis: 'x3',
    yaxis: 'y3',
    mode: 'lines',
    line: {color: '#9a9a9a'},
	 showlegend: false 
  };
  

  var vw = window.innerWidth * 0.55;
  var vh = 550; // put 3 plots together

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
      tickformat: '%H:%M:%S', // Set the tick format for time values
      tickmode: 'linear', // Use linear tick mode for consistent tick spacing
      tick0: new Date().getTime(), // Start the ticks from the current time
      dtick: 5000, // Set the tick interval to 5s
      showticklabels: true, // Show tick labels
      domain: [0, 1],
		 showticklabels: false
    },
    yaxis: {
      domain: [plotHeight * 2 + plotSpacing * 2, plotHeight * 3 + plotSpacing * 2], // 0.5, 0.7
      range: [0, 3.4],
      tickformat: '.2f',
      tickmode: 'array',
      tickvals: [0, 1, 3, 3.3]
    },

    xaxis2: { // RPM
      type: 'date', 
      anchor: 'y2', 
      tickformat: '%H:%M:%S', // Set the tick format for time values
      tickmode: 'linear', // Use linear tick mode for consistent tick spacing
      tick0: new Date().getTime(), // Start the ticks from the current time
      dtick: 5000, // Set the tick interval to 5s
      showticklabels: true, // Show tick labe
      domain: [0, 1],
		showticklabels: false
    },
    yaxis2: {
      anchor: 'x2', 
      domain: [plotHeight + plotSpacing, plotHeight * 2 + plotSpacing], //0.25, 0.45 P2
      range: [0, 510],
      tickmode: 'array',
      tickvals: [0, 100, 300, 500]
    },

    xaxis3: { // PWR
      type: 'date', 
      anchor: 'y3', 
      tickformat: '%H:%M:%S', // Set the tick format for time values
      tickmode: 'linear', // Use linear tick mode for consistent tick spacing
      tick0: new Date().getTime(), // Start the ticks from the current time
      dtick: 5000, // Set the tick interval to 5s
      showticklabels: true, // Show tick labe
      domain: [0, 1]
    },
    yaxis3: {
      anchor: 'x3', 
      domain: [0, plotHeight],
      range: [0, 11],
      tickmode: 'array',
      tickvals: [0, 2, 4, 6, 8, 10]
    }
  }

  var ws_plot_title = {
    x: 0.5, 
    y: plotHeight * 3 + plotSpacing * 3,
    xref: 'paper', 
    yref: 'paper',
    text: "Wind Speed: " + document.getElementById("wind-speed-value").textContent + "m/s",
    showarrow: false // Hide arrow for cleaner look
  };

    var rpm_plot_title = {
    x: 0.5, 
    y: plotHeight * 2 + plotSpacing,
    xref: 'paper', 
    yref: 'paper',
    text: "RPM: " + document.getElementById("rpm-value").textContent,
    showarrow: false // Hide arrow for cleaner look
  };

  var pwr_plot_title = {
    x: 0.5, 
    y: plotHeight,
    xref: 'paper',
    yref: 'paper',
    text: "OUTPUT POWER: " + document.getElementById("pwr-value").textContent + "W",
    showarrow: false // Hide arrow for cleaner look
  };
  
  // Add annotation to layout
  layout.annotations = [pwr_plot_title, rpm_plot_title, ws_plot_title];

  var data = [trace1,trace2,trace3]; 
  
  Plotly.plot('graph', data, layout);  
  
  var cnt = 0;
  
  var interval = setInterval(function() {
    
    var time = new Date();
    
    var update = {
      x: [[time], [time], [time]],
      y: [[rand() * 3.3], [rand() * 500], [rand() * 10]]
    }
    
    Plotly.extendTraces('graph', update, [0,1,2])
    
    if(cnt === 100) clearInterval(interval);
  }, 1000);
  