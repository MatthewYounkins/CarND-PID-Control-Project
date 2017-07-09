# -*- coding: utf-8 -*-
"""
Created on Sat Jul  8 11:09:18 2017

@author: root
"""
import subprocess32
import time
import os
import signal
import subprocess

method = 5;

if method == 1:
## This works, but doesn't stop every so often?
    p1 = subprocess32.Popen(['./pid', '1.2', '.5', '3', '.7', '0'], stdout=subprocess32.PIPE, shell=True, preexec_fn=os.setsid)
    #time.sleep(2)   #this was never useful
#    os.killpg(os.getpgid(p1.pid), signal.SIGTERM) 
    #out, err = p1.communicate()
    #return_code = p1.poll()

if method == 2:
## This works, but doesn't stop every so often?
    time.sleep(1)
    print('Starting')
    p1 = subprocess.Popen(['./pid', '1.2', '.5', '3', '.7', '0'], stdout=subprocess.PIPE, shell=True, preexec_fn=os.setsid)
    time.sleep(2)   #this was never useful
#    os.killpg(os.getpgid(p1.pid), signal.SIGTERM) 
    #out, err = p1.communicate()
    #return_code = p1.poll()

if method == 3:
## This works, but doesn't stop every so often?
    time.sleep(1)
    print('Starting')
    p1 = subprocess.Popen(['./pid', '1.2', '.5', '3', '.7', '0'], stdout=subprocess.PIPE)
    out, err = p1.communicate()
    time.sleep(5)   #this was never useful
    p1.kill()
#    time.sleep(1)
#    p1 = subprocess.Popen(['./pid', '-50', '0', '0', '0', '0'], stdout=subprocess.PIPE)   
#    os.killpg(os.getpgid(p1.pid), signal.SIGTERM) 
    #out, err = p1.communicate()
    #return_code = p1.poll()

if method == 4:
    # This stops the process after 3 seconds and doesn't re-continue?
    for _ in range(10):
        output = subprocess32.check_output(['./pid', '1.2', '.5', '3', '.7', '0'], stderr=subprocess32.STDOUT, timeout=3)
        print(_)
              
def functionToRun(Kp, Ki, Kd, fM, Kq):
    result = subprocess.check_output(['./pid', '1.2', '.5', '3', '.7', '0'])
    output = result.stdout
    return output    

if method == 5:    
    output = functionToRun('1.2','.5','3','.7','0')   
    
#splitString = out.split('CTE')
    

#print(out)


#p = Popen(['program', 'arg1'], stdin=PIPE, stdout=PIPE, stderr=PIPE)
#output, err = p.communicate(b"input data that is passed to subprocess' stdin")
#rc = p.returncode



#for _ in range(999999): # or whatever
#    p1 = subprocess.Popen(['pid', '1', '1', '1', '1', '1'])
#    time.sleep(0.1)  # wait a small amount of time, hopefully the process ends fast
#    return_code = p1.poll()
#
#    if return_code is not None: # we're happy, the process ended fast
#        ... # do something to celebrate
#    else:  # we're sad. let the process run for at most 5 seconds
#        time.sleep(5)   
#        p1.terminate()    # this kills the process. try p1.kill() too...
#        p1.wait()   #  this cleans up the process registry.