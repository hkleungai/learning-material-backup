import java.io.* ;
import java.net.* ;
import java.util.* ;

public final class ProxyServer {
	public static void main(String argv[]) throws Exception {

	// Set the port number.
	int port = 8080;

	// Establish the listen socket.
	/* Fill in */

	// Process HTTP service requests in an infinite loop.
	while (true) {
		// Listen for a TCP connection request.
		/* Fill in */

		// Construct an object to process the HTTP request message.
		HttpRequest request = new HttpRequest( /* Fill in */ );

		// Create a new thread to process the request.
		Thread thread = new Thread(request);

		// Start the thread.
		thread.start();

		}

	}

}
