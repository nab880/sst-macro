#ifndef CONNECTION_H
#define CONNECTION_H

#include <sstmac/common/event_scheduler.h>
#include <sstmac/common/event_callback.h>
#include <sprockit/sim_parameters_fwd.h>

#define connectable_type_invalid(ty) \
   spkt_throw_printf(sprockit::value_error, "invalid connectable type %s", connectable::str(ty))

#define connect_str_case(x) case x: return #x

namespace sstmac {
namespace hw {



class connectable
{
 public:
  virtual std::string
  to_string() const = 0;

  static const int any_port = -1;

  virtual void
  connect_output(
    sprockit::sim_parameters* params,
    int src_outport,
    int dst_inport,
    event_handler* handler) = 0;

  virtual void
  connect_input(
    sprockit::sim_parameters* params,
    int src_outport,
    int dst_inport,
    event_handler* handler) = 0;

  virtual link_handler*
  ack_handler(int port) const = 0;

  virtual link_handler*
  payload_handler(int port) const = 0;

};

class connectable_component :
  public event_scheduler,
  public connectable
{
 protected:
  connectable_component(sprockit::sim_parameters* params,
                        uint64_t cid,
                        event_loc_id id,
                        event_manager* mgr,
                        event_handler* self)
    : event_scheduler(params, cid, id, mgr, self)
  {
  }

};

class connectable_subcomponent :
  public event_subscheduler,
  public connectable
{
protected:
 connectable_subcomponent(event_scheduler* parent,
                          event_handler* self)
   : event_subscheduler(parent, self)
 {
 }
};

}
}

#endif // CONNECTION_H

