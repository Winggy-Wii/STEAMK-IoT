const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
  <head>
    <title>ESP-NOW DASHBOARD</title>
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <link
      rel="stylesheet"
      href="https://use.fontawesome.com/releases/v5.7.2/css/all.css"
      integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr"
      crossorigin="anonymous"
    />
    <link rel="icon" href="data:," />
    <style>
      html {
        font-family: Arial;
        display: inline-block;
        text-align: center;
      }
      h1 {
        font-size: 2rem;
      }
      body {
        margin: 0;
      }
      .topnav {
        overflow: hidden;
        background-color: #2f4468;
        color: white;
        font-size: 1.7rem;
      }
      .content {
        padding: 20px;
      }
      .card {
        background-color: white;
        box-shadow: 2px 2px 12px 1px rgba(140, 140, 140, 0.5);
      }
      .cards {
        max-width: 700px;
        margin: 0 auto;
        display: grid;
        grid-gap: 2rem;
        grid-template-columns: repeat(auto-fit, minmax(320px, 1fr));
      }
      .reading {
        font-size: 2.8rem;
      }
      .timestamp {
        color: #bebebe;
        font-size: 1rem;
      }
      .card-title {
        font-size: 1.2rem;
        font-weight: bold;
      }
      .card.temperature {
        color: #b10f2e;
      }
      .card.humidity {
        color: #50b8b4;
      }
    </style>
  </head>
  <body>
    <div class="topnav">
      <h1>Sensor Dashboard</h1>
    </div>
    <div class="content">
      <div class="cards">
        <div class="card temperature">
          <p class="card-title">
            <i class="fas fa-thermometer-half"></i>TEMPERATURE
          </p>
          <p>
            <span class="reading"
              ><span id="t1">%TEMPERATURE% </span>&deg;C</span
            >
          </p>
        </div>
        <div class="card humidity">
          <p class="card-title">
            <i class="fas fa-tint"></i>HUMIDITY
          </p>
          <p>
            <span class="reading"
              ><span id="h1"> %HUMIDITY% </span> &percnt;</span
            >
          </p>
        </div>
      </div>
    </div>
    <script>
      setInterval(function () {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("t1").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "/temperature", true);
        xhttp.send();
      }, 10000);
      setInterval(function () {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("h1").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "/humidity", true);
        xhttp.send();
      }, 10000);
    </script>
  </body>
</html>
)rawliteral";
