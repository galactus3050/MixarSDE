import argparse
from concurrent.futures import ThreadPoolExecutor
from metrics import compute_metrics
from optimizer import optimize

def process(mesh):
    return compute_metrics(mesh)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", required=True)
    parser.add_argument("--threads", type=int, default=4)
    args = parser.parse_args()

    meshes = ["cube", "sphere", "cylinder"]
    with ThreadPoolExecutor(args.threads) as ex:
        results = list(ex.map(process, meshes))

    optimize(results)

if __name__ == "__main__":
    main()
