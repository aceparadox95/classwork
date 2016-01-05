var apiKey = 'fa7d80c48643dfadde2cced1b1be6ca1';
document.addEventListener('DOMContentLoaded', bindButtons);
function bindButtons(){
	document.getElementById('urlSubmit').addEventListener('click', function(event){
	var req = new XMLHttpRequest();
	var zipCode = document.getElementById('zip').value;
	var inpCity = document.getElementById('city').value;
	var inpState = document.getElementById('state').value;
	if (zipCode > 0){
		req.open("GET", "http://api.openweathermap.org/data/2.5/weather?zip=" + zipCode + ",US" + "&appid=" + apiKey, true);
	}
	else{
		req.open("GET", "http://api.openweathermap.org/data/2.5/weather?q=" + inpCity + "," + inpState + "&appid=" + apiKey, true);
	}
	req.addEventListener('load',function(){
		if(req.status >= 200 && req.status < 400){
			var responseObject = JSON.parse(req.responseText);
			var tempF = (responseObject.main.temp) * (9/5) - 459.67;
			document.getElementById('cityDisp').textContent = "City: " + responseObject.name;
			document.getElementById('temp').textContent = "Temperature(Fahrenheit): " + tempF;
			document.getElementById('humidity').textContent = "Humidity: " + responseObject.main.humidity;
		}
		else{
			console.log("Error in network request" + request.statusText);
		}});
		req.send(null);
		event.preventDefault();
		});
}