/**
 * 
 */
package sk.boinc.nativeboinc.nativeclient;

/**
 * @author mat
 *
 */
public interface NativeBoincUpdateListener extends AbstractNativeBoincListener {
	public abstract void updatedProjectApps(String projectUrl);
}
