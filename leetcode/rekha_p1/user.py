class User(object):
    _id = None
    def __init__(self, username, password):
        self.username = username
        self.password = password
    
    def setUserName(self, username):
        self.username = username
    
    def getUsername(self):
        return self.username

    def setPassword(self,password):
        self.password = password

    def getPassword(self):
        return self.password
    
    def setid(self, id):
        self._id = id
    
    def getId(self):
        return self._id