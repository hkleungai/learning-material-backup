students = {
    "10042": "Mary",
    "10067": "John",
    "12029": "Andy",
    "11047": "Molly",
    "12334": "Jane"
}

def search(studentid):
    if studentid in students:
        return students[studentid]
    else:
        return None

print(search("10067"))
print(search("10022"))
