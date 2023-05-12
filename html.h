const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
  <head>
    <title>ESP Web Server</title>
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <link rel="icon" href="data:," />
    <style>
      html {
        font-family: Arial, Helvetica, sans-serif;
        text-align: center;
      }
      h1 {
        font-size: 3rem;
        color: white;
        text-align: center;
      }
      h2 {
        font-size: 1.5rem;
        font-weight: bold;
        color: #143642;
      }
      .topnav {
        overflow: hidden;
        border-bottom: 0.3rem black solid;
        background-color: #143642;
      }
      body {
        margin: 0;
      }
      .content {
        padding: 30px;
        max-width: 600px;
        margin: 0 auto;
      }
      .button {
        font-weight: bold;
        width: 12rem;
        height: 6rem;
        margin-top: 5rem;
        padding: 1.5rem 2rem;
        font-size: 2rem;
        text-align: center;
        outline: none;
        color: #fff;
        background-color: #0f8b8d;
        border: 0.3rem solid;
        border-color: black;
        border-radius: 0.5rem;
        -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;

        -webkit-tap-highlight-color: rgba(0, 0, 0, 0);
      }
      .align {
        position: absolute;
        top: 50%;
        left: 50%;
        transform: translate(-50%, -50%);
      }
      /*.button:hover {background-color: #0f8b8d}*/
      .button:active {
        background-color: #0f8b8d;
        box-shadow: 2 2px #cdcdcd;
        transform: translateY(2px);
      }
      .state {
        font-size: 1.5rem;
        color: #8c8c8c;
        font-weight: bold;
      }
    </style>
    <title>ESP Web Server</title>
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <link rel="icon" href="data:," />
  </head>
  <body>
    <div class="topnav">
      <h1>Toggle LED</h1>
    </div>
    <div class="align">
      <p>
        <button id="on" class="button" onclick="toggleCheckbox(this)">
          ON
        </button>
      </p>
      <p>
        <button id="off" class="button" onclick="toggleCheckbox(this)">
          OFF
        </button>
      </p>
    </div>
    <div class="content"></div>
    <script>
      function toggleCheckbox(element) {
        var xhr = new XMLHttpRequest();
        if (element.id == "on") {
          xhr.open("GET", "/update?&state=1", true);
        } else {
          xhr.open("GET", "/update?state=0", true);
        }
        xhr.send();
      }
    </script>
  </body>
</html>
)rawliteral";
