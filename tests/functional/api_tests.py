#!/usr/bin/env python
import requests
import unittest
import json
from subprocess import call
from multiprocessing import Process
import os
import signal
from time import sleep


class testTallerifyAppServer(unittest.TestCase):
    def testPing(self):
        sleep(1) # To allow server to start =)
        response = requests.get('http://localhost:8080/ping')
        self.assertEqual(200, response.status_code)


suite = unittest.TestLoader().loadTestsFromTestCase(testTallerifyAppServer)


def startAppServer():
    #call([""])
    call(["/fiuba-taller2-tallerify-app-server/build/fiuba_taller2_tallerify_app_server"])


def killAppServer():
    for line in os.popen("ps ax | grep fiuba_taller2_tallerify_app_server | grep -v grep"):
        fields = line.split()
        pid = fields[0]
    os.kill(int(pid), signal.SIGKILL)


def runTests():
    unittest.TextTestRunner(verbosity=2).run(suite)


t1 = Process(target=startAppServer, args=())
t2 = Process(target=runTests, args=())
t1.start()
t2.start()
t2.join()
killAppServer()
