def optimize(results):
    best = min(results, key=lambda x: x["stretch"])
    print("Best:", best)
