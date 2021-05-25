class pbook:
    pbook_list = []
    book_name = None
    def __init__(self, book_name):
        self.book_name = book_name
        # return None

    def add(self, phone_number):
        self.pbook_list.append(phone_number)
        # return None
    def get_list(self):
        return self.pbook_list

def solution(phone_book):
    dict_phone_number = dict()
    for phone in phone_book:
        dict_phone_number[phone] = 1
    print(dict_phone_number)
    
    for i in range(1, len(phone_book)):
        phone_number = phone_book[i]
        prev_phone_number = phone_book[i -1]
        if prev_phone_number != phone_number:
            if phone_number[0:min(len(phone_number),len(prev_phone_number))] \
                == prev_phone_number[0:min(len(phone_number),len(prev_phone_number))]:
                return False
    return True


phone_book1 = ["119", "97674223", "1195524421"]
phone_book2 = ["123","456","789"]
phone_book3 = ["12","123","1235","567","88"]

print(solution(phone_book1))
print(solution(phone_book2))
print(solution(phone_book3))