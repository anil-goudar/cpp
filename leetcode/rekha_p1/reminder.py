'''
                CREATE TABLE IF NOT EXISTS reminder (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    uid INTEGER,
                    date TEXT,
                    subject TEXT,
                    description TEXT,
                    email TEXT,
                    contactno INTEGER,
                    smsno INTEGER,
                    validdays INTEGER,
                    isdisabled INTEGER
                )
                '''
import uuid

class Reminder(object):
    def __init__(self, id, uid, date, subject, description, email, contactno, smsno, validdays, isdisabled):
        self.id = id
        self.uid = uid
        self.date = date
        self.description = description
        self.subject = subject
        self.email = email
        self.contactno = contactno
        self.smsno = smsno
        self.validdays = validdays
        self.isdisabled = isdisabled
    
    def setUID(self, uid):
        self.uid = uid
    
    def getUID(self):
        return self.uid

    def setid(self, id):
        self.id = id
    def getId(self):
        return self.id

    def setDate(self, date):
        self.date = date
    def getDate(self):
        return self.date
    
    def setSubject(self, sub):
        self.subject = sub
    def getSubject(self):
        return self.subject
    
    def setDescription(self, desc):
        self.description = desc
    def getDescription(self):
        return self.description
    
    def getEmail(self):
        return self.email
    def setEmail(self, mail):
        self.email = mail
    
    def getContactNo(self):
        return self.contactno
    def setContactNo(self, cno):
        self.contactno = cno

    def getSmsNo(self):
        return self.smsno
    def setSmsNo(self, sno):
        self.smsno = sno
    
    def getValidDays(self):
        return self.validdays
    def setValidDays(self, vd):
        self.validdays = vd
    
    def getDisabled(self):
        return self.isdisabled
    def setDisabled(self, dis):
        self.isdisabled = dis