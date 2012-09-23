#include <mcal/mcal.h>
#include <util/utility/util_time.h>

namespace app
{
  namespace led
  {
    void task_init();
    void task_func();
  }
}

namespace
{
  typedef util::timer<std::uint32_t> timer_type;
  timer_type app_led_timer;
}

void app::led::task_init()
{
  app_led_timer.start_interval(timer_type::seconds(1U));

  mcal::led::led0.toggle();
}

void app::led::task_func()
{
  if(app_led_timer.timeout())
  {
    app_led_timer.start_interval(timer_type::seconds(1U));

    mcal::led::led0.toggle();
  }
}
