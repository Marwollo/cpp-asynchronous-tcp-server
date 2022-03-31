#include <iostream>
#include <common/common.hpp>

class Session : public std::enable_shared_from_this<Session>
{
private:
    asio::ip::tcp::socket socket;
    asio::streambuf stream_buffer;

public:
    Session(asio::ip::tcp::socket &&socket) : socket(std::move(socket))
    {
    }

    void Start()
    {
        asio::async_read_until(socket, stream_buffer, "\n", [self = shared_from_this()](asio::error_code error, std::size_t bytes_transferred)
        {
            std::cout << std::istream(&self->stream_buffer).rdbuf(); 
        });
    }
};

class Server
{
private:
    asio::io_context &io_context;
    asio::ip::tcp::acceptor acceptor;
    std::optional<asio::ip::tcp::socket> socket;

public:
    Server(asio::io_context &io_context, std::uint16_t port) : io_context(io_context), acceptor(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
    {
    }

    void AsyncAccept()
    {
        socket.emplace(io_context);
        acceptor.async_accept(*socket, [&](asio::error_code error)
        { 
            std::make_shared<Session>(std::move(*socket))->Start();
            this->AsyncAccept(); 
        });
    }
};

int main()
{
    asio::io_context io_context;
    Server server(io_context, 15001);
    server.AsyncAccept();
    io_context.run();
    return 0;
}
