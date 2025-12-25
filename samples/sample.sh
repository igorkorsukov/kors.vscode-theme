
trap 'echo Build failed; exit 1' ERR

if [ $(which nproc) ]; then
    JOBS=$(nproc --all)
else
    JOBS=4
fi
TARGET=release

while [[ "$#" -gt 0 ]]; do
    case $1 in
        -t|--target) TARGET="$2"; shift;;
        -j|--jobs) JOBS="$2"; shift;;
        -h|--help) SHOW_HELP=1;;
        *) echo "Unknown parameter passed: $1"; exit 1 ;;
    esac
    shift
done

mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=$TARGET ..
make -j$JOBS

