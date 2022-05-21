import java.io.* ;
import java.net.* ;
import java.util.* ;

public final class MailServer {
	public static void main(String argv[]) throws Exception {

		/* Set the port number. */
		int port = 25;

		/* Establish the listen socket. */
        ServerSocket mailSocket = new ServerSocket(port);

		/* Process SMTP client requests in an infinite loop. */
		while (true) {
			/* Listen for a TCP connection request. */
			Socket SMTPSocket = mailSocket.accept();

			/* Construct an object to process the SMTP request. */
			SMTPConnection connection = new SMTPConnection(SMTPSocket);

			/* Create a new thread to process the request. */
			Thread thread = new Thread(connection);

			/* Start the thread. */
			thread.start();
		}
	}
}
