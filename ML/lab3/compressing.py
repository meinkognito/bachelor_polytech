from sklearn.cluster import KMeans
from PIL import Image, ImageDraw


def task_3(count_clusters):
    img = Image.open("data/kirovsk.jpg")
    draw = ImageDraw.Draw(img)
    width = img.size[0]
    height = img.size[1]
    pix = img.load()
    data = []
    for x in range(width):
        for y in range(height):
            data.append([pix[x, y][0], pix[x, y][1], pix[x, y][2]])
    kmeans_model = KMeans(n_clusters=count_clusters).fit(data)
    dict = {}
    for i in range(count_clusters):
        dict.update({i: kmeans_model.cluster_centers_[i]})
    for x in range(width):
        for y in range(height):
            r = int(dict[kmeans_model.labels_[x * height + y]][0])
            g = int(dict[kmeans_model.labels_[x * height + y]][1])
            b = int(dict[kmeans_model.labels_[x * height + y]][2])
            draw.point((x, y), (r, g, b))
    img.save("results/3/result" + str(count_clusters) + ".jpg", "JPEG")


number_of_clusters = [100, 50, 25, 10, 5, 3]
for cl in number_of_clusters:
    task_3(cl)
