$('#nav').affix({
      offset: {
        top: $('header').height()
      }
});

var map = new ol.Map({
	target: 'map', //This target value points back to the original name of the div in your html file and is the first argument passed into a map object
	layers: [ //The second argument in the map object is the wonderful layers we've been waiting for. In this case it's grabbing raster satellite imagery from MapQuest
	  new ol.layer.Tile({
		source: new ol.source.MapQuest({layer: 'sat'})
	  })
	],
	view: new ol.View({//The last argument in the map object is the view object which specifies the initial extent and location of the map
	  center: ol.proj.fromLonLat([37.41, 8.82]),
	  zoom: 4
	})
});

var map2 = new ol.Map({
	target: 'coolermap', //This target value points back to the original name of the div in your html file and is the first argument passed into a map object
	layers: [ //The second argument in the map object is the wonderful layers we've been waiting for. In this case it's grabbing raster satellite imagery from MapQuest
	  new ol.layer.Tile({
		source: new ol.source.MapQuest({layer: 'osm'})
	  })
	],
	view: new ol.View({//The last argument in the map object is the view object which specifies the initial extent and location of the map
	  center: ol.proj.fromLonLat([-123.281405, 44.559567]),
	  zoom: 18
	})
});

var vectorLayer = new ol.layer.Vector({
  source: new ol.source.Vector({
    url: 'assets/restaurants2.kml',
    format: new ol.format.KML()
  })
});

var map3 = new ol.Map({
	target: 'vectormap', //This target value points back to the original name of the div in your html file and is the first argument passed into a map object
	layers: [ //The second argument in the map object is the wonderful layers we've been waiting for. In this case it's grabbing raster satellite imagery from MapQuest
	  new ol.layer.Tile({
		source: new ol.source.MapQuest({layer: 'sat'})
	  }),
	  vectorLayer
	],
	view: new ol.View({//The last argument in the map object is the view object which specifies the initial extent and location of the map
	  center: ol.proj.fromLonLat([-116.205211, 43.614823]),
	  projection: 'EPSG:3857',
	  zoom: 18
	})
});