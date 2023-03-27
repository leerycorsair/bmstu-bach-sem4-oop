#include "action.h"

error_t action_process(const action_t &action)
{
  static model_t model = model_init();
  error_t error_code;
  switch (action.task)
  {
  case MOVE_MODEL:
    error_code = model_move(model, action.move_data);
    break;
  case SCALE_MODEL:
    error_code = model_scale(model, action.scale_data);
    break;
  case ROTATE_MODEL:
    error_code = model_rotate(model, action.rotate_data);
    break;
  case LOAD_MODEL:
    error_code = model_load(model, action.load_data);
    break;
  case RENDER_MODEL:
    error_code = model_render(model, action.render);
    break;
  case EXIT:
    error_code = SUCCESS;
    model_free(model);
    break;
  }
  return error_code;
}
