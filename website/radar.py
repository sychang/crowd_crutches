from flask import Flask, request, session, g, redirect, url_for, \
     abort, render_template, flash

import requests

app = Flask(__name__)
app.config.from_object(__name__)

@app.route('/')
def map_page():
    return render_template('index.html')

@app.route('/add_marker')
def add_marker():
	lat = request.args.get('lat')
	lon = request.args.get('lon')
	data = {'lat':lat, 'lng': lon}
	r = requests.post('https://blistering-inferno-357.firebaseIO.com/coords.json', json=data)
	# r = requests.post('https://blistering-inferno-357.firebaseIO.com/coords.json', data = {'lat':lat, 'lng': lon}, verify=True)
	print r
   	return "empty"

if __name__ == '__main__':
    app.run(debug=True)