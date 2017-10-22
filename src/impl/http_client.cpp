#include <ostream>
#include <boost/asio.hpp>

class HTTPClient {

    public:
        HTTPClient() :
        socket_(io_service_),
        resolver_(io_service_)
        {};

        void Get() {};
        void Post() {};

    private:
        boost::asio::io_service io_service_;
        boost::asio::ip::tcp::resolver resolver_;
        boost::asio::ip::tcp::socket socket_;

        void request() {
            boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(), argv[1], argv[2]);
            boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver_.resolve(query);
            boost::asio::connect(socket, endpoint_iterator);

			// Form the request. We specify the "Connection: close" header so that the
		    // server will close the socket after transmitting the response. This will
		    // allow us to treat all data up until the EOF as the content.
			boost::asio::streambuf request;
    		std::ostream request_stream(&request);
    		request_stream << "GET " << argv[3] << " HTTP/1.0\r\n";
    		request_stream << "Host: " << argv[1] << "\r\n";
    		request_stream << "Accept: */*\r\n";
    		request_stream << "Connection: close\r\n\r\n";

			// Send the request.
			boost::asio::write(socket, request);
}

};
