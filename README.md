# Vehicle
Komputer pokładowy składa się z dwóch komponentów: <b>vehicle-server</b> oraz <b>vehicle-qml</b> <br><br>
Plik źródłowe <b>vehicle-qml</b> znajdują się pod obecnym linkiem:<br>
https://github.com/lukomski/vehicle-qml<br>
natomiast pliki źródłowe <b>vehicle-server</b> znajdują się tutaj: <br>
https://github.com/lukomski/vehicle-server

0. Zbudowanie plików binarnych

	Pliki binarne należy budować na innym komputerze niż Raspberry pi, pod procesor, który znajduje się na płytce PI.
	Przygotowanie obydwu komputerów pod kompilacje krzyżową jest dobrze opisane w poniższym linku:<br>
	https://mechatronicsblog.com/cross-compile-and-deploy-qt-5-12-for-raspberry-pi/

1. Przygotowanie Raspberry pi do uruchomienia programu

  	Należy odkomentować ostatnią lini w <b>/etc/apt/source.list</b>, a następnie wykonać poniższe polecenia
		
		$ sudo apt update
		$ sudo apt-get install qt5-default
		$ sudo apt-get install qtcreator
		$ sudo apt install qml-module-qtquick-extras                   
		$ sudo apt install qml-module-qtcharts
2. Uruchomienie programu

		$ ./vehicle-server
		$ ./vehicle-qml
		
3. Dodatkowa konfiguracja

	Programy <b>vehicle-server</b> oraz <b>vehicle-qml</b> czytają odpowiednio pliki konfiguracyjne <b>vehicle-server.conf</b> oraz <b>vehicle-qml</b>
	
	Przykładowy plik konfiguracyjny <b>vehicle-server.conf</b>:<br>
		```
		listenPort = 1234
		```<br>
		```
		logFileName = ""
		```<br>
		Przykładowy plik konfiguracyjny <b>vehicle-qml.conf</b>:<br>
		```
		serverIp = 127.0.0.1
		```<br>
		```
		serverPort = 1234
		```<br><br>
		Powyższa konfiguracja jest ustawiania domyślnie, w przypadku, gdy nie ma pliku konfiguracyjnego.
