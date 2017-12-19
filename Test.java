public class Test {

	static {
		System.load("c:/Users/agd/swrepo/dist/Debug/MinGW-Windows/AsrarsAgent.dll");

		// System.load("C:/Users/agd/swrepo/dist/Debug/MinGW-Windows/AsrarsAgent.dll");
		System.out.println(callAG("This is an arg"));
		/*
		 * try { String name = ManagementFactory.getRuntimeMXBean().getName(); String id =
		 * name.split("@")[0]; VirtualMachine vm = VirtualMachine.attach(id); vm.loadAgentLibrary(
		 * "C:/Users/agd/swrepo/dist/Debug/MinGW-Windows/AsrarsAgent.dll"
		 * ); } catch (AttachNotSupportedException | IOException | AgentLoadException |
		 * AgentInitializationException ex) {
		 * Logger.getLogger(Test.class.getName()).log(Level.SEVERE, null, ex); }
		 */
	}



	public static void main(String args[]) {
		System.out.println("Hello World 2!");

		// String nativeReturnedString = callAG("Calling Agent");
		// System.out.println(nativeReturnedString);
	}

	// public static native Thread... getThreadsFromTi();

	public static native String callAG(String arg);

	// public static native void init();
}
