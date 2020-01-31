import sqlite3
from user import User
from reminder import Reminder

userTable = '''
            CREATE TABLE IF NOT EXISTS user (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT NOT NULL,
            password TEXT NOT NULL
            )
            '''

reminderTable = '''
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

'''
    validateUser():
    takes user object and database object
    checks weather user is valid or not
    logs in on successfull
    else 
    ask for retry
'''
def validateUser(user, dbCurr):
    try:
        query = '''SELECT * FROM user WHERE username=? AND password=?;'''
        data = (user.getUsername(), user.getPassword())
        cur = dbCurr.cursor()
        cur.execute(query,data)
        if cur.fetchone() is None:
            return -1
        else:
            query = '''SELECT id FROM user WHERE username=? AND password=?;'''
            data = (user.getUsername(), user.getPassword())
            cur.execute(query,data)
            res = cur.fetchone()
            return res[0]
    except sqlite3.Error as e:
        print(e)


'''
    insertIntoUserTable()
    inserts a new user row into user table
'''
def insertIntoUserTable(user, dbCurr):
    query = '''INSERT INTO user (username, password)
            VALUES (?, ?);'''
    data = (user.getUsername(), user.getPassword())
    try:
        dbCurr.execute(query, data)
        print('Inserted a row into user table...')
        return True
    except sqlite3.Error as e:
        print(e)

def insertNewReminder(r, dbCurr):
    query = '''INSERT INTO reminder (id, userid, date, subject, description, email, contactno, smsno, validdays, isdisabled) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?);'''
    data = (r.getId(), r.getUID(), r.getDate(), r.getSubject(), r.getDescription(), r.getEmail(),
    r.getContactNo(), r.getSmsNo(), r.getValidDays(), r.getDisabled())
    try:
        curr = dbCurr.cursor()
        curr.execute(query, data)
        print('Inserted a row into reminder table')
        dbCurr.commit()
    except sqlite3.Error as e:
        print(e)


def getAllReminders(dbConn, id):
    query = '''SELECT * FROM reminder WHERE userid=?;'''
    curr = dbConn.cursor()
    try:
        curr.execute(query, (id,))
        reminders = []
        records = curr.fetchall()
        for res in records:
            reminders.append(res)
        return reminders
    except sqlite3.Error as e:
        print(e)

def disableReminder(dbConn, id):
    query = '''UPDATE reminder SET isdisabled=1 WHERE id=?;'''
    curr = dbConn.cursor()
    try:
        curr.execute(query, (id,))
    except sqlite3.Error as e:
        print(e)

'''
    connectToDatabase():
    Creates or connects to existing database
    and returns the connection cursor
    of the database.
'''

def connectToDatabase():
    try:
        connection = sqlite3.connect('reminders.db')
        print('Connected to database!!')
        return connection
    except sqlite3.Error as error:
        print('Database connection Error: ', error)

'''
    createTables():
    Creates user and reminder tables in the given
    database cursor object
'''
def createTables(dbCurr):
    try:
        dbCurr.execute(userTable)
        dbCurr.execute(reminderTable)
        print('Tables are created...')
    except sqlite3.Error as error:
        print('Tables already created.', error)
        return

def closeDatabase():
    connection = sqlite3.connect('reminders.db')
    connection.close()


# if __name__ == "__main__":
#     dbCurr = connectToDatabase()
#     createTables(dbCurr)
#     print('Continuing...')
#     user = User('anil', 'anil')
#     insertIntoUserTable(user,dbCurr)
#     user = User('sunil', 'sunil')
#     insertIntoUserTable(user,dbCurr)
#     select = 'SELECT * FROM user;'
#     dbCurr.execute(select)
#     rows = dbCurr.fetchall()
#     print('total rows: ', len(rows))
#     for row in rows:
#         print(row[0], row[1], row[2])
#     validUser = validateUser(user, dbCurr)

#     dbCurr.close()