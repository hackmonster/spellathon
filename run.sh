echo OFF
adb root
adb remount
pushd jni
ndk-build -B -j4
popd
adb push src/words_eng.txt /data/
adb shell "chmod 777 /data/words_eng.txt"
adb push libs/armeabi-v7a/spellChecker /data/
adb shell "chmod 777 /data/spellChecker" 
adb shell ./data/spellChecker $1
