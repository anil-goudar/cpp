def filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance):
        if len(restaurants) == 0:
            return 
        if veganFriendly == 0:
            rs = sorted(restaurants, key = lambda x: x[0], reverse=True)
            rs = sorted(rs, key = lambda x: x[1], reverse = True)
            ls = []
            ln = len(restaurants)
            for i in range(ln):
                if rs[i][3] <= maxPrice and rs[i][4] <= maxDistance:
                    ls.append(rs[i][0])
            return ls
        else:
            rs = list(filter(lambda x: x[2] == 1, restaurants))
            rs = sorted(rs, key = lambda x: x[0], reverse=True)
            rs = sorted(rs, key = lambda x: x[1], reverse = True)
            ls = []
            ln = len(rs)
            for i in range(ln):
                if rs[i][3] <= maxPrice and rs[i][4] <= maxDistance:
                    ls.append(rs[i][0])
            return ls

ls = [[1,4,1,40,10]]
vf = 0
mp = 30
md = 3

print(filterRestaurants(ls, vf, mp, md))