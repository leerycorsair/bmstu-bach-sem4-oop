#include "error.h"

void error_show_info(const error_t &error_code)
{
  switch (error_code)
  {
  case FILE_CANT_BE_OPENED:
    QMessageBox::critical(NULL, "Ошибка", "Ошибка открытия файла.");
    break;
  case NO_POINTS:
    QMessageBox::critical(NULL, "Ошибка", "Недостаточно точек.");
    break;
  case VERTICES_SIZE_ERROR:
    QMessageBox::critical(NULL, "Ошибка", "Некорректное количество вершин.");
    break;
  case EDGES_SIZE_ERROR:
    QMessageBox::critical(NULL, "Ошибка", "Некорректное количество ребер.");
    break;
  case UNSUCCESSFUL_MEMORY_ALLOCATION:
    QMessageBox::critical(NULL, "Ошибка", "Ошибка выделения памяти.");
    break;
  case INCORRECT_FILE:
    QMessageBox::critical(NULL, "Ошибка", "Некорректное содержимое файла.");
    break;
  default:
    QMessageBox::critical(NULL, "Ошибка", "Неизвестная команда.");
  }
}
