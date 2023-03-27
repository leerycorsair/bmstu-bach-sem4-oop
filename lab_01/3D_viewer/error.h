#ifndef ERROR_H
#define ERROR_H

#include <QMessageBox>

enum error_t
{
  SUCCESS,
  FILE_CANT_BE_OPENED,
  NO_POINTS,
  VERTICES_SIZE_ERROR,
  EDGES_SIZE_ERROR,
  UNSUCCESSFUL_MEMORY_ALLOCATION,
  INCORRECT_FILE
};

void error_show_info(const error_t &error_code);

#endif // ERROR_H
