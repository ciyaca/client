#include <feverrpc/feverrpc.hpp>
#include <feverrpc/utils.hpp>

namespace FeverRPC {
class Server : public FeverRPC {

  public:
    ~Server();
    // server to client
    void s2c();
    // client to server
    void c2s();
    template <typename Ret, typename... Args>
    // !send a note, !deprecated!
    Ret note(const int socket_handler, std::string name, Args... args);
  private:
    // !inner call of send a note, !deprecated!
    template <typename Ret>
    Ret note_socket_call(const int socket_handler, msgpack::sbuffer &buffer);
};
// FeverRPC::Server

template <typename Ret, typename... Args>
Ret Server::note(const int socket_handler, std::string name, Args... args) {
    msgpack::sbuffer buffer;
    msgpack::packer<msgpack::sbuffer> pk(&buffer);
    pk.pack(name);
    pk.pack(std::make_tuple(args...));
    return note_socket_call<Ret>(socket_handler, buffer);
}

template <typename Ret>
Ret Server::note_socket_call(const int socket_handler,
                             msgpack::sbuffer &buffer) {
    send_data(socket_handler, buffer.data(), buffer.size());
    msgpack::sbuffer recv_buff;
    recv_data(socket_handler, recv_buff);
    return unpack_ret_val<Ret>(recv_buff);
}

} // namespace FeverRPC