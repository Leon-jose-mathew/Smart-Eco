// File generated by FlutterFire CLI.
// ignore_for_file: lines_longer_than_80_chars, avoid_classes_with_only_static_members
import 'package:firebase_core/firebase_core.dart' show FirebaseOptions;
import 'package:flutter/foundation.dart'
    show defaultTargetPlatform, kIsWeb, TargetPlatform;

/// Default [FirebaseOptions] for use with your Firebase apps.
///
/// Example:
/// ```dart
/// import 'firebase_options.dart';
/// // ...
/// await Firebase.initializeApp(
///   options: DefaultFirebaseOptions.currentPlatform,
/// );
/// ```
class DefaultFirebaseOptions {
  static FirebaseOptions get currentPlatform {
    if (kIsWeb) {
      return web;
    }
    switch (defaultTargetPlatform) {
      case TargetPlatform.android:
        return android;
      case TargetPlatform.iOS:
        return ios;
      case TargetPlatform.macOS:
        return macos;
      case TargetPlatform.windows:
        throw UnsupportedError(
          'DefaultFirebaseOptions have not been configured for windows - '
          'you can reconfigure this by running the FlutterFire CLI again.',
        );
      case TargetPlatform.linux:
        throw UnsupportedError(
          'DefaultFirebaseOptions have not been configured for linux - '
          'you can reconfigure this by running the FlutterFire CLI again.',
        );
      default:
        throw UnsupportedError(
          'DefaultFirebaseOptions are not supported for this platform.',
        );
    }
  }

  static const FirebaseOptions web = FirebaseOptions(
    apiKey: 'AIzaSyBH9RJILm5SQQMBR2lHQz8KV4KWUWWJuBM',
    appId: '1:433736581248:web:5c3f9bb06516948ec3e665',
    messagingSenderId: '433736581248',
    projectId: 'smarteco-61678',
    authDomain: 'smarteco-61678.firebaseapp.com',
    databaseURL: 'https://smarteco-61678-default-rtdb.asia-southeast1.firebasedatabase.app',
    storageBucket: 'smarteco-61678.appspot.com',
    measurementId: 'G-TLJ7XLJVMV',
  );

  static const FirebaseOptions android = FirebaseOptions(
    apiKey: 'AIzaSyAFLJf5OBlqSLt6f1qJIRcYFN9_awh7Mrg',
    appId: '1:433736581248:android:a1f04d133681bb48c3e665',
    messagingSenderId: '433736581248',
    projectId: 'smarteco-61678',
    databaseURL: 'https://smarteco-61678-default-rtdb.asia-southeast1.firebasedatabase.app',
    storageBucket: 'smarteco-61678.appspot.com',
  );

  static const FirebaseOptions ios = FirebaseOptions(
    apiKey: 'AIzaSyC2dQVycVra-hV8GjgGCHp_h_flrVVyaLw',
    appId: '1:433736581248:ios:df00ba857b268962c3e665',
    messagingSenderId: '433736581248',
    projectId: 'smarteco-61678',
    databaseURL: 'https://smarteco-61678-default-rtdb.asia-southeast1.firebasedatabase.app',
    storageBucket: 'smarteco-61678.appspot.com',
    iosBundleId: 'com.example.smarteco2',
  );

  static const FirebaseOptions macos = FirebaseOptions(
    apiKey: 'AIzaSyC2dQVycVra-hV8GjgGCHp_h_flrVVyaLw',
    appId: '1:433736581248:ios:b404940124392edac3e665',
    messagingSenderId: '433736581248',
    projectId: 'smarteco-61678',
    databaseURL: 'https://smarteco-61678-default-rtdb.asia-southeast1.firebasedatabase.app',
    storageBucket: 'smarteco-61678.appspot.com',
    iosBundleId: 'com.example.smarteco2.RunnerTests',
  );
}
