package buoi3;

import java.net.InetAddress;

public class Connected {
	private InetAddress ip;
	private int port;

	public Connected() {
	}

	public Connected(InetAddress ip, int port) {
		this.ip = ip;
		this.port = port;
	}

	public InetAddress getIp() {
		return ip;
	}

	public void setIp(InetAddress ip) {
		this.ip = ip;
	}

	public int getPort() {
		return port;
	}

	public void setPort(int port) {
		this.port = port;
	}
}
