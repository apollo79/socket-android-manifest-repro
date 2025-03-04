// vim: set sw=2:
package com.socket
import java.lang.ref.WeakReference

interface IRuntimeConfiguration {
  val rootDirectory: String
  val assetManager: android.content.res.AssetManager
  val exit: (Int) -> Unit
  val openExternal: (String) -> Unit
}

data class RuntimeConfiguration (
  override val rootDirectory: String,
  override val assetManager: android.content.res.AssetManager,
  override val exit: (Int) -> Unit,
  override val openExternal: (String) -> Unit
) : IRuntimeConfiguration

open class Runtime (
  activity: MainActivity,
  configuration: RuntimeConfiguration
) {
  var pointer = alloc(activity.getRootDirectory())
  var activity = WeakReference(activity)
  val configuration = configuration;
  var isRunning = false

  fun finalize () {
    if (this.pointer > 0) {
      this.dealloc()
    }

    this.pointer = 0
  }

  fun exit (code: Int) {
    this.configuration.exit(code)
  }

  fun openExternal (value: String) {
    this.configuration.openExternal(value)
  }

  fun start () {
    if (!this.isRunning) {
      this.resume()
      this.isRunning = true
    }
  }

  fun stop () {
    if (this.isRunning) {
      this.pause()
      this.isRunning = false
    }
  }

  fun destroy () {
    this.stop()
    this.finalize()
  }

  @Throws(java.lang.Exception::class)
  external fun alloc (rootDirectory: String): Long;

  @Throws(java.lang.Exception::class)
  external fun dealloc (): Boolean;

  external fun isDebugEnabled (): Boolean;

  @Throws(java.lang.Exception::class)
  external fun pause (): Boolean;

  @Throws(java.lang.Exception::class)
  external fun resume (): Boolean;

  @Throws(java.lang.Exception::class)
  external fun startEventLoop (): Boolean;

  @Throws(java.lang.Exception::class)
  external fun stopEventLoop (): Boolean;

  @Throws(java.lang.Exception::class)
  external fun startTimers (): Boolean;

  @Throws(java.lang.Exception::class)
  external fun stopTimers (): Boolean;

  @Throws(java.lang.Exception::class)
  external fun isPermissionAllowed (permission: String): Boolean;

  @Throws(java.lang.Exception::class)
  external fun setIsEmulator (value: Boolean): Boolean;

  @Throws(java.lang.Exception::class)
  external fun getConfigValue (key: String): String;
}
