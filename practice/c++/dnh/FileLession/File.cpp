#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>

using namespace std;

struct Employee {
  _int32 ID;
  char name[50];
};

Employee emps[3] = {
    {1, "Harry Potter"}, {2, "Hermione Granger"}, {3, "Ron Weasley"}};
///////////////////////////////////////////////////////////////
void writeToFilErr(FILE *file) {
  const char *s = "Hello everyone!";
  fwrite(s, strlen(s), 1, file);
}

void readFromFileErr(FILE *file) {
  void *ptr = operator new(255); // allocate 255 bytes on Heap
  fread(ptr, 255, 1, file);
  (static_cast<char *>(ptr))[255] = '\0';
  std::cout << static_cast<char *>(ptr) << std::endl;
}
/////////////////////////////////////////////////////////////
void writeToFile(FILE *file) {
  for (int i = 0; i < 3; i++) {
    fwrite(&emps[i], sizeof(Employee), 1, file);
  }
}

void readFromFile(FILE *file) {
  Employee emp;
  for (int i = 0; i < 3; i++) {
    fread(&emp, sizeof(Employee), 1, file);

    std::cout << emp.ID << std::endl;
    std::cout << emp.name << std::endl;
    std::cout << "================================" << std::endl;
  }
}
///////////////////////////////////////////////////////////////////
void readDataFromStream(std::string file) {
  // std::ifstream fileInput(file);
  std::fstream fileInput(file, std::ios::in);
  if (fileInput.fail()) {
    std::cout << "Cannot open file at" << std::endl;
    return;
  }
  while (fileInput.eof()) {
    char line[255];
    fileInput.getline(line, 255);
    cout << line << endl;
  }
}

void writeDataFromStream(std::string file) {
  // std::ofstream fileOutput(file);
  std::fstream fileOutput(file, std::ios::out);

  if (fileOutput.fail()) {
    std::cout << "Cannot open file at" << std::endl;
    return;
  }
  // Note: in fstream method, new text is override all old text in file.

  fileOutput << "Hello Kitty" << endl;
  fileOutput << "Hello ..." << endl;
  fileOutput << "Harry Potter" << endl;
  fileOutput << "Hermione Granger" << endl;
  fileOutput << "Ron Weasley" << endl;
}
////////////////////////////////////////////////////////////////
int main() {
  // file path use '/'
  const char *filePath = "H:/document/ProgramingTech_OOP/filetest.txt";
  const char *filePath2 = "H:/document/ProgramingTech_OOP/file2test.txt";
  const char *filePath3 = "H:/document/ProgramingTech_OOP/file3test.txt";
  FILE *file;
  FILE *file2;
  errno_t err;

  file = fopen(filePath, "w+b");

  err = fopen_s(&file2, filePath2, "a+");

  if (file) {
    cout << "File is not null" << endl;
    // 1. write
    /*int c = fputc('A',file);

    for (int i = 0; i < 5; i++)
    {
            fprintf(file, "\nI must challenge myselft!",i);
    }*/

    // 2. write binary
    /*writeToFileErr(file);
    fseek(file, 0, SEEK_SET);*/

    // 3. read
    /*std::cout << (char)fgetc(file) << std::endl;
    char str[255];
    std::cout << fgets(str, 255, file) << endl;
    cout << str << endl;*/

    // 4. read binary
    // readFromFileErr(file);

    // 5. write binary 2
    // writeToFile(file);
    // fseek(file, 0, SEEK_SET);

    // 6. read binary 2
    // readFromFile(file);

    // 7. read write
    writeDataFromStream(filePath3);
    fseek(file, 0, SEEK_SET);
    readDataFromStream(filePath3);
    err = fclose(file);
  } else {
    cout << "File is null" << endl;
  }

  if (err != 0) {
    cout << "File2 is null" << endl;
  } else {
    cout << "File2 is not null" << endl;
    // write
    int c2 = fputs("hello heyjo!", file2);
    fseek(file2, 0, SEEK_SET);
    /*for (int i = 0; i < 5; i++)
    {
            fprintf(file2, "\nI must challenge myselft!", i);
    }*/
    // read
    /*char str[255];
    fscanf(file, "hello", str);
    cout << str << endl;*/

    err = fclose(file2);
  }

  system("pause");
  return 0;
}
