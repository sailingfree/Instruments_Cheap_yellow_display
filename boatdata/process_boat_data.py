##########################################################
"""Convert the internal log to gpx format"""
##########################################################

import json

from xml.dom import minidom

root = minidom.Document()

gpx = root.createElement('gpx')
gpx.setAttribute("version", "1.0")
root.appendChild(gpx)

bounds = root.createElement("bounds")
gpx.appendChild(bounds)

trk = root.createElement('trk')

gpx.appendChild(trk)
trkseg = root.createElement('trkseg')
trk.appendChild(trkseg)

class DataPoint:  # pylint: disable=too-few-public-methods
    """Class representing a single data point"""
    __slots__ = ('ms', 'val')
    def __init__(self, ms, val):
        self.ms = ms
        self.val = val

    def __str__(self):
        return f"{self.ms},{self.val}\n "


class DataPoints:
    """Class containing 0 or more DataPoints"""
    def __init__(self):
        self.points = []

    def __str__(self):
        for d in self.points:
            dpresult += d.__str__()
        return dpresult



    def add(self, ms, val):    
        """Add a new data point to the collection"""
        self.points.append(DataPoint(ms,val))


keys = ["sog", "cog", "rpm", "angle", "wind", "depth", "lat", "lon", "time", "days", "seconds"]
result = {}

for k in keys:
    result[k] = DataPoints()

lastdepth = 0.0
minlat = 90.0
maxlat = 0.0
minlon = 180.0
maxlon = -180

with open("logfile3-10-7-to-old-harry.txt", mode="r", encoding="utf-8") as read_file:
    rdata = read_file.readlines()
    for l in rdata:
 
        jdata = json.loads(l)

        if "n2kdata" in jdata:
            n2kdata = jdata['n2kdata']

            for key in keys:
                if key in n2kdata:
                    ms = jdata['ms']
                    val = n2kdata[key]
                #    print(ms, ',', key, ',', val)
                    p = result[key]
                    p.add(ms,val)

                    if key == 'depth':
                        lastdepth = n2kdata['depth']

                    if key == "lat":
                        lat = n2kdata["lat"]
                        lon = n2kdata["lon"]
                        time = n2kdata["time"]
                        trkpt = root.createElement('trkpt')
                        trkpt.setAttribute('lat', str(lat))
                        trkpt.setAttribute('lon', str(lon))
                        trkpt.setAttribute('time', time)
                        trkpt.setAttribute('depth', str(lastdepth))
                        trkseg.appendChild(trkpt)

                        if lat < minlat:
                            minlat = lat
                        if lat > maxlat:
                            maxlat = lat
                        if lon < minlon:
                            minlon = lon
                        if lon > maxlon:
                            maxlon = lon

# set the bounds
bounds.setAttribute("minlat", str(minlat))
bounds.setAttribute("minlon", str(minlon))
bounds.setAttribute("maxlat", str(maxlat))
bounds.setAttribute("maxlon", str(maxlon))


xml_str = root.toprettyxml(indent ="\t")  

save_path_file = "route.gpx"

with open(save_path_file, "w", encoding="utf-8") as f:
    f.write(xml_str)
