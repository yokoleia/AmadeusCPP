To Compile, make sure to point the compiler to the subdirectories: 

g++ -I./Accounts -I./DAO -I./Helpers main.cpp Bank.cpp Customer.cpp Accounts/BankAccount.cpp Accounts/SavingsAccount.cpp Accounts/FixedAccount.cpp Helpers/UserInput.cpp DAO/FileDAO.cpp