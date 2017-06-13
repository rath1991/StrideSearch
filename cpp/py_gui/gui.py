#!/usr/bin/python

import Tkinter as tk
import subprocess as sub


#########################################################################
# def __init__(self,parent):                                            #
#     Tkinter.Tk.__init__(self,parent)                                  #
#     self.parent = parent                                              #
#     self.minsize(300,300)                                             #
#     self.initialize()                                                 #
#                                                                       #
# def initialize(self):                                                 #
#     top = self                                                        #
#     tex=Tkinter.Text()                                                #
#     tex.pack(side=Tkinter.BOTTOM)                                     #
#     button = Tkinter.Button(self,text=u"Run Stride Search",           #
#                             command = self.OnButtonClick(tex)).pack() #
#########################################################################
    
def OnButtonClick():
    p = sub.Popen('../build/bin/ssLLDataTest.exe', stdout=sub.PIPE,stderr=sub.PIPE)
    output, errors = p.communicate()
    tex.insert(tk.END,output)

if __name__ == "__main__":
    root = tk.Tk()
    root.title("Stride Search")

    tex = tk.Text()
    tex.pack(side=tk.BOTTOM);
    tex.see(tk.END)
    
    button = tk.Button(text="Run Stride Search", command=OnButtonClick)
    button.pack()

    root.mainloop()
