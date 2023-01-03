# android-ExampleBinder
android-ExampleBinder

## Add to Android
```bash
PRODUCT_PACKAGES += example_binder_client example_binder_server
```
## Run command
```bash
example_binder_server &
example_binder_client
logcat | grep "ExampleBinderClient"
```
