import tkinter as tk
from tkinter import ttk
import database as db
from user import User
from reminder import Reminder
import uuid

def home():
    global window
    window = tk.Tk()
    window.title("Home Page")
    
    style= ttk.Style()
    colour=style.configure("TButton", foreground = "blue")

    
        
    bt2=ttk.Button(window,text="Welcome to the Reminder Application "+"<<" +user_var.get()+">>")
    bt2.grid(columnspan=2,row=13,)
    bt2=ttk.Button(window,text="Today is Tuessday,14th of February.")
    bt2.grid(columnspan=2,row=14)
    bt3=ttk.Button(window,width=18,text="Set Reminder Screen", command=set_reminder,style=colour)
    bt3.grid(column=1,row=15)
    bt4=ttk.Button(window,width=18,text="Modify Reminder Screen",command=modify_reminder)
    bt4.grid(column=1,row=16)
    bt5=ttk.Button(window,width=18,text="Disable Reminder Screen",command= disable_reminder)
    bt5.grid(column=1,row=17)
    bt6=ttk.Button(window,width=18,text="Delete an existing Reminder",command=delete)
    bt6.grid(column=1,row=18)
    bt7=ttk.Button(window,width=18,text="Enable a Reminder",command=enable_reminder)
    bt7.grid(column=1,row=19)
    bt8=ttk.Button(window,width=18,text="View your Reminders",command=view_reminder)
    bt8.grid(column=1,row=20)
    bt9=ttk.Button(window,style=colour,width=14,text="Log Out",command=Logout)
    bt9.grid(column=4,row=21)
    bt10=ttk.Button(window,width=14,text="Back",command=clicked)
    bt10.grid(column=0,row=21)
    window.mainloop()

    window.quit()

from tkinter import messagebox

def confirm():
    window = tk.Tk()
    window.title("Confirm")
    messagebox.showinfo('Thank you',"Your transaction is confirmed  ").pack()
    button=ttk.Button(window,width=14,text="Log Out",command=Logout)
    button.pack()
    
def Logout():
    messagebox.showinfo('Log out',"Your have been logged out  ")
    
def cancel():
    messagebox.showinfo('cancel',"Your have been logged out  ")
def disable_reminder():
    window = tk.Tk()
    window.title("Disable Reminder Screen")
    lb=ttk.Label(window,text="Disable Reminder",font=('bold',10)).grid(column=0,row=0)
    bt1=ttk.Label(window,text="Select a Date:")
    bt1.grid(column=1,row=4)
    seldate_var=tk.IntVar()
    contect_entry=ttk.Entry(window,width=16,textvariable=seldate_var)
    contect_entry.grid(column=2,row=4)

    bt1=ttk.Label(window,text="Select Subject:")
    bt1.grid(column=1,row=5)
    bt1=ttk.Label(window,text="Reminders:")
    bt1.grid(column=1,row=6)
    bt1=ttk.Label(window,text="Description:")
    bt1.grid(column=1,row=7)

    description_var=tk.StringVar()
    des_combobox=ttk.Combobox(window, width=14,textvariable=description_var, state='readonly')
    des_combobox['values']=('Important' , 'Causaul','General')
    des_combobox.grid(column=2,row=7)


    combo_Reminders=ttk.Combobox(window,width=14,values=['a','c','z'],state='readonly')
    combo_Reminders.grid(column=2,row=6)

    combo_subject=ttk.Combobox(window,width=14, values=['Birthday','anniversary','Event'],state='readonly')
    combo_subject.grid(column=2,row=5)
       

    bt8=ttk.Button(window,text="Black",command=clicked)
    bt8.grid(column=1,row=14)
    bt9=ttk.Button(window,text="Confirm",command=confirm)
    bt9.grid(column=2,row=14)
    lb1=ttk.Button(window,text="Log out",command=Logout)
    lb1.grid(column=10,row=14)


def enable_reminder():
    window = tk.Tk()
    window.title("enable Reminder Screen")
    lb=ttk.Label(window,text="Enable Reminder",font=('bold',10)).grid(column=0,row=0)
    bt1=ttk.Label(window,text="Select a Date:")
    bt1.grid(column=1,row=3)

    seldate_var=tk.IntVar()
    contect_entry=ttk.Entry(window,width=16,textvariable=seldate_var)
    contect_entry.grid(column=2,row=3)
    bt1=ttk.Label(window,text="Recur for next:")
    bt1.grid(column=1,row=11)
    bt1=ttk.Label(window,text="Select Subject:")
    bt1.grid(column=1,row=5)
    bt1=ttk.Label(window,text="Reminders:")
    bt1.grid(column=1,row=6)
    bt1=ttk.Label(window,text="Description:")
    bt1.grid(column=1,row=7)
    bt1=ttk.Label(window,text="Email Address:")
    bt1.grid(column=1,row=8)
    bt1=ttk.Label(window,text="Contect No:")
    bt1.grid(column=1,row=9)
    bt1=ttk.Label(window,text="SMS No:")
    bt1.grid(column=1,row=10)

    contect_var=tk.StringVar()
    contect_entry=ttk.Entry(window,width=14,textvariable=contect_var)
    contect_entry.grid(column=2,row=8)

    Email_var=tk.StringVar()
    name_entrybox = ttk.Entry(window,width=14,textvariable = Email_var)
    name_entrybox.grid(row=7,column=2)
    SMS_var=tk.StringVar()
    name_entrybox = ttk.Entry(window,width=14,textvariable = SMS_var)
    name_entrybox.grid(row=10,column=2)
    destination_var=tk.StringVar()
    contect_entry=ttk.Entry(window,width=14,textvariable=destination_var)
    contect_entry.grid(column=2,row=9)

    combo_Reminders=ttk.Combobox(window,width=14,values=['a','c','z'],state='readonly')
    combo_Reminders.grid(column=2,row=6)

    combo_subject=ttk.Combobox(window,width=14,values=['Birthday','anniversary','Event'],state='readonly')
    combo_subject.grid(column=2,row=5)

    recur_check=ttk.Combobox(window,width=14,values=['7 Days','5 Days','3 Days','2 Days'] ,state='readonly').grid(column=2,row=11)


        

    bt8=ttk.Button(window,text="Black",command=clicked)
    bt8.grid(column=1,row=14)
    bt9=ttk.Button(window,text="Confirm",command=confirm)
    bt9.grid(column=2,row=14)
    lb1=ttk.Button(window,text="Log out",command=Logout)
    lb1.grid(column=10,row=14)

    window.mainloop()
def set_reminder():
    window = tk.Tk()
    window.title("Set Reminder Screen")
    lb=ttk.Label(window,text="Set a new Reminder",font=('bold',10)).grid(column=0,row=0)

        
    bt1=ttk.Label(window,text="Select a Date:")
    bt1.grid(column=1,row=3)

    seldate_var=tk.StringVar()
    contect_entry_date=ttk.Entry(window,width=16,textvariable=seldate_var)
    contect_entry_date.grid(column=2,row=3)

    
    bt1=ttk.Label(window,text="Recur for next:")
    bt1.grid(column=1,row=10)
    
    bt1=ttk.Label(window,text="Subject:")
    bt1.grid(column=1,row=5)
    
    bt1=ttk.Label(window,text="Add description:")
    bt1.grid(column=1,row=6)
    bt1=ttk.Label(window,text="Email Address:")
    bt1.grid(column=1,row=7)
    bt1=ttk.Label(window,text="Contect No:")
    bt1.grid(column=1,row=8)
    bt1=ttk.Label(window,text="SMS No:")
    bt1.grid(column=1,row=9)

    contect_var=tk.StringVar()
    contect_entry=ttk.Entry(window,width=16,textvariable=contect_var)
    contect_entry.grid(column=2,row=8)

    Email_var=tk.StringVar()
    name_entrybox = ttk.Entry(window,width=16,textvariable = Email_var)
    name_entrybox.grid(row=7,column=2)

    SMS_var=tk.StringVar()
    name_entrybox1 = ttk.Entry(window,width=16,textvariable = SMS_var)
    name_entrybox1.grid(row=9,column=2)

    description_var=tk.StringVar()
    contect_entry1=ttk.Entry(window,width=16,textvariable=description_var)
    contect_entry1.grid(column=2,row=6)

    recur_check = ttk.Combobox(window,values=['7 Days','5 Days','3 Days','2 Days'] ,state='readonly')
    recur_check.grid(column=2,row=10)

    combo_subject = ttk.Combobox(window,values=['Birthday','Anniversary','Event'],state="readonly")
    combo_subject.grid(column=2,row=5)

    


    #subject = 

    '''def verify():
        sub = combo_subject.get()
        mail = name_entrybox.get()
        cno = contect_entry.get()
        sno = name_entrybox1.get()
        desc = contect_entry1.get()
        
        print(sub, mail, cno, sno, desc)'''

    def confirm():
        date = contect_entry_date.get()
        sub = combo_subject.get()
        mail = name_entrybox.get()
        contactno = contect_entry.get()
        sno = name_entrybox1.get()
        desc = contect_entry1.get()
        validdays = recur_check.get()
        id = str(uuid.uuid1())
        global curr_user
        global dbConnect
        uid = curr_user.getId()
        reminder = Reminder(id, uid, date, sub, desc, mail, contactno, sno, validdays, 0)
        success = db.insertNewReminder(reminder, dbConnect)
        if success:
            print('Inserted')
            ''''back to home'''


    bt8=ttk.Button(window,text="Back",command=clicked)
    bt8.grid(column=1,row=15)
    bt9=ttk.Button(window,text="Confirm", command=confirm)
    bt9.grid(column=2,row=15)
    lb1=ttk.Button(window,text="Log out",command=Logout)
    lb1.grid(column=10,row=15)


    window.mainloop()

def modify_reminder():
    global dbConnect
    global curr_user
    id = curr_user.getId()
    reminders = db.getAllReminders(dbConnect, id)
    ln = len(reminders)
    nextc = len(reminders[0])
    colm = 1
    j = 0
    child = tk.Toplevel(window)
    child.title("Modify Reminder")
    for r in reminders:
        lb=ttk.Label(child,text="Modify Reminder",font=('bold',10)).grid(column=0,row=0+j)
        bt1=ttk.Label(child,text="Select a Date:")
        bt1.grid(column=colm,row=3+j)
        seldate_var=tk.StringVar(child,r[2])
        contect_entry=ttk.Entry(child,width=14,textvariable=seldate_var)
        contect_entry.grid(column=2,row=3+j)


        bt1=tk.Label(child,text="Recur for next:")
        bt1.grid(column=colm,row=11+j)
        bt1=ttk.Label(child,text="Select Subject:")
        bt1.grid(column=colm,row=5+j)
        bt1=ttk.Label(child,text="Add description:")
        bt1.grid(column=colm,row=7+j)
        bt1=ttk.Label(child,text="Email Address:")
        bt1.grid(column=colm,row=8+j)
        bt1=ttk.Label(child,text="Contect No:")
        bt1.grid(column=colm,row=9+j)
        bt1=ttk.Label(child,text="SMS No:")
        bt1.grid(column=colm,row=10+j)

        contect_var=tk.StringVar(child, r[6])
        contect_entry=ttk.Entry(child,width=14,textvariable=contect_var)
        contect_entry.grid(column=colm+1,row=9+j)

        Email_var=tk.StringVar(child, r[5])
        name_entrybox = ttk.Entry(child,width=14,textvariable = Email_var)
        name_entrybox.grid(row=8+j,column=colm+1)
        SMS_var=tk.StringVar(child, r[7])
        name_entrybox = ttk.Entry(child,width=14,textvariable = SMS_var)
        name_entrybox.grid(row=10+j,column=colm+1)
        description_var=tk.StringVar(child, r[4])
        contect_entry=ttk.Entry(child,width=14,textvariable=description_var)
        contect_entry.grid(column=colm+1,row=7+j)

        # combo_Reminders=ttk.Combobox(window,width=14,values=['a','z','c'],state='readonly')
        # combo_Reminders.grid(column=colm+1,row=6)
        sub = tk.StringVar(child, r[3])
        combo_subject=ttk.Combobox(child,width=14, textvariable=sub, values=['Birthday','Anniversary','Event'],   state='readonly')

        combo_subject.grid(column=colm+1,row=5+j)
        days = tk.StringVar(child, r[8])
        recur_check=ttk.Combobox(child,values=['7 Days','5 Days','3 Days','2 Days'] ,width=14, state='readonly', textvariable=days)
        recur_check.grid(column=colm+1,row=11+j)

        
        j = j+2
        j += nextc
        
    bt8=ttk.Button(child,text="Back",command=child.destroy)
    bt8.grid(column=colm,row=16+j)
    bt9=ttk.Button(child,text="Confirm",command=confirm)
    bt9.grid(column=colm,row=16+j)
    lb1=ttk.Button(child,text="Log out",command=Logout)
    lb1.grid(column=10,row=16+j)
    window.mainloop()
    window.quit()

def view_reminder():
    window = tk.Tk()
    window.title("View your Reminders")
    label1 = ttk.Label(window,text="View your Reminders  " ,font=("times romain Bold",10)).grid(column=0,row=0, sticky=tk.W)
    label2 = ttk.Label(window,text="Select From Date : " ).grid(column=1,row=1, sticky=tk.W)
    seldate_var=tk.IntVar()
    contect_entry=ttk.Entry(window,width=18,textvariable=seldate_var)
    contect_entry.grid(column=2,row=1)
    label3 = ttk.Label(window,text="Select To Date : " ).grid(column=4,row=1, sticky=tk.W)
    seldate_var=tk.IntVar()
    contect_entry=ttk.Entry(window,width=18,textvariable=seldate_var)
    contect_entry.grid(column=5,row=1)
    label4 = ttk.Label(window,text="Subject : ").grid(column=1,row=4, sticky=tk.W)
    label4 = ttk.Label(window,text="Reminder Name ").grid(column=1,row=6, sticky=tk.W)

    label4 = ttk.Label(window,text="Reminder Subject ").grid(column=2,row=6, sticky=tk.W)

    label4 = ttk.Label(window,text="Reminder Description").grid(column=3,row=6, sticky=tk.W)

    label4 = ttk.Label(window,text="Email Address ").grid(column=4,row=6, sticky=tk.W)
    label4 = ttk.Label(window,text="Contact No ").grid(column=5,row=6, sticky=tk.W)


    label4 = ttk.Label(window,text="SMS No ").grid(column=6,row=6, sticky=tk.W)

    label4 = ttk.Label(window,text="Status ").grid(column=7,row=6, sticky=tk.W)


    label4 = ttk.Label(window,text="Recurrence Frequency ").grid(column=8,row=6, sticky=tk.W)


    check=tk.IntVar()
    check_box=ttk.Checkbutton(window,text="Select a reminder for futher operations",variable=check).grid(column=9,row=6)


    label5 = ttk.Button(window,text="Log Out ",command=Logout).grid(column=10,row=12)



    combo_subject=ttk.Combobox(window,values=['Birthday','anniversary','Event'],state='readonly')
    combo_subject.grid(column=2,row=4)

    bt1=ttk.Button(window,text="Back",command=clicked)
    bt1.grid(column=1,row=12)

    bt2=ttk.Button(window,text="Delete Reminder",command=delete)
    bt2.grid(column=2,row=12)

    bt2=ttk.Button(window,text="Disable Reminder",command=disable_reminder)
    bt2.grid(column=3,row=12)

    bt2=ttk.Button(window,text="Modify Reminder",command=modify_reminder)
    bt2.grid(column=4,row=12)


    window.mainloop()
def confirm():
    window = tk.Tk()
    window.title("confirm")
    lb=ttk.Label(window,text="Thank you").grid(column=6,row=2)
    bt1=ttk.Label(window,text="Your transaction is confirmed")
    bt1.grid(column=6,row=3)

    lb1=ttk.Button(window,text="Log out")
    lb1.grid(column=10,row=6)

    window.mainloop()

def delete():
    window = tk.Tk()
    window.title("Delete Reminder")
    lb=ttk.Label(window,text="Delete Reminder",font=('bold',10)).grid(column=0,row=0)
    bt1=ttk.Label(window,text="Select Date:")
    bt1.grid(column=1,row=4)
    seldate_var=tk.IntVar()
    contect_entry=ttk.Entry(window,width=18,textvariable=seldate_var)
    contect_entry.grid(column=2,row=4)

    
    bt1=ttk.Label(window,text="Select Subject:")
    bt1.grid(column=1,row=5)
    bt1=ttk.Label(window,text="Reminders:")
    bt1.grid(column=1,row=6)
    bt1=ttk.Label(window,text="Description:")
    bt1.grid(column=1,row=7)

    description_var=tk.StringVar()
    des_combobox=ttk.Combobox(window, width=14,textvariable=description_var, state='readonly')
    des_combobox['values']=('Important' , 'Causaul','General')
    des_combobox.grid(column=2,row=7)


    combo_Reminders=ttk.Combobox(window,width=14,values=['a','c','z'],state='readonly')
    combo_Reminders.grid(column=2,row=6)

    combo_subject=ttk.Combobox(window,width=14, values=['Birthday','anniversary','Event'],state='readonly')
    combo_subject.grid(column=2,row=5)
       

    bt8=ttk.Button(window,text="Back",command=clicked)
    bt8.grid(column=1,row=14)
    bt9=ttk.Button(window,text="Confirm",command=confirm)
    bt9.grid(column=2,row=14)
    lb1=ttk.Button(window,text="Log out",command=Logout)
    lb1.grid(column=10,row=14)


    window.mainloop()

     
window = tk.Tk()
window.title("Login")
label1 = ttk.Label(window,text="Username : " ,font=("times romain Bold",10)).grid(column=1,row=0, sticky=tk.W)
label2 = ttk.Label(window,text="Password : " ,font=("times romain Bold",10)).grid(column=1,row=1, sticky=tk.W)
def clicked():
    username=user_var.get()
    password=pass_var.get()
    global dbConnect
    user = User(username, password)
    uid = db.validateUser(user, dbConnect)
    if uid > 0:
        user.setid(uid)
        global curr_user  
        curr_user = user
        home()
    else:
        messagebox.showinfo('Login Failed'," Login Failed ")

    
        

bt1=ttk.Button(window,text="Login",command=clicked)
bt1.grid(column=1,row=12)

    
bt2=ttk.Button(window,text="Cancel",command=Logout)
bt2.grid(column=2,row=12)
user_var=tk.StringVar()
name_entrybox = ttk.Entry(window,width=16,textvariable = user_var)
name_entrybox.grid(row=0,column=2)
pass_var=tk.StringVar()
name_entrybox = ttk.Entry(window,show="*",width=16,textvariable = pass_var)
name_entrybox.grid(row=1,column=2)

if __name__ == "__main__":
    global dbConnect
    global curr_user
    dbConnect = db.connectToDatabase()
    window.mainloop()
    window.quit()
