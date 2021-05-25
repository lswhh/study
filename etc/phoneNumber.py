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

# class HashTable:
#     hash_table = [0] * 20
#     def __init__(self): 
#         self.hash_table = list([0 for i in range(8)]) 
#     def hash_function(self, key): 
#         return key % 8 
#     def insert(self, key, value): 
#         hash_value = self.hash_function(hash(key)) 
#         self.hash_table[hash_value] = value 
#     def read(self, key): 
#         hash_value = self.hash_function(hash(key)) 
#         return self.hash_table[hash_value] 
#     def print(self): 
#         print(self.hash_table)

def solution(phone_book):
    # phone_book_class = pbook('test_book')
    # for phone_number in phone_book:
    #     phone_book_class.add(phone_number)
    # print(phone_book_class.book_name, phone_book_class.pbook_list)
    phone_book.sort()
    # phone = sorted(phone_book, key=lambda x : (x,len(x)))
    # phone = sorted(phone_book)

    # print("phoneList: ", phone)
    # for i, txt in enumerate(phone):
    #     print("enumerate: ", i, "txt: ", txt)
    for outer_phone_number in phone_book:
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