## Import necessary library
import torch, os
import torch.nn as nn
import torch.nn.functional as F
from torchvision import datasets, transforms as T
import torch.optim as opt

device = "cuda" if torch.cuda.is_available() else "cpu"
## Load dataset
root = "./data"
os.makedirs(root, exist_ok=True)
preprocess = T.Compose([
    T.ToTensor(),
    ## use random transformation here to do data augmentation
    T.Normalize(mean=(0.5, ), std=(1,))
])
train_set = datasets.MNIST(root, train=True, transform=preprocess, download=True)
test_set = datasets.MNIST(root, train=False, transform=preprocess, download=True)

batch_size = 100
## use dataloader allows you to prefetch next batch in parallel (if num_workers > 1),
## meanwhile, the gpu is handling the previous one. This could give a better GPU utilization
 ## shuffle to prevent correlation within batch
train_loader = torch.utils.data.DataLoader(train_set, batch_size=batch_size, shuffle=True, num_workers=2)
test_loader = torch.utils.data.DataLoader(test_set, batch_size=batch_size, shuffle=False)

## Define Network
class LeNet(nn.Module):
    def __init__(self):
        super(LeNet, self).__init__()
        self.conv1 = nn.Conv2d(1, 20, 5)
        self.pool1 = nn.MaxPool2d(2, 2)
        self.conv2 = nn.Conv2d(20, 50, 5)
        self.pool2 = nn.MaxPool2d(2, 2)
        self.flatten = nn.Flatten()
        self.fc1 = nn.Linear(50*4*4, 500)
        self.fc2 = nn.Linear(500, 10)

    def forward(self, x):
        ## (N, 1, 28, 28)
        h = F.relu(self.conv1(x))
        ## (N, 20, 24, 24)
        h = self.pool1(h)
        ## (N, 20, 12, 12)
        h = F.relu(self.conv2(h))
        ## (N, 50, 8, 8)
        h = self.pool2(h)
        ## (N, 50, 4, 4)
        h = self.flatten(h)
        ## (N, 50*4*4)
        h = F.relu(self.fc1(h))
        logits = self.fc2(h)
        return logits

net = LeNet()
net.to(device)

loss_fn = F.cross_entropy
optim = opt.SGD(net.parameters(), lr=0.01, momentum=0.9)

acc_fn = lambda x,y: (1.0*(x.argmax(-1) == y)).mean()

epoch_nums = 5
for i in range(1, epoch_nums+1):
    ## training
    for c, (x, y) in enumerate(train_loader):
        optim.zero_grad()
        x, y = x.to(device), y.to(device)
        logits = net(x)
        loss = loss_fn(logits, y)
        if c % 100 == 0 or c == len(train_loader) - 1:
            print("epoch: {}, batch: {:4}, loss_train: {:7.5}, acc_train: {:5.2%}".format(
                i, c,
                loss.data.item(),
                acc_fn(logits, y).data.item()
                ))
        loss.backward()
        optim.step()
    ## test
    loss = 0
    acc = 0
    with torch.no_grad(): ## stop gradient to simplify the forward
        for c, (x, y) in enumerate(test_loader):
            x, y = x.to(device), y.to(device)
            logits = net(x)
            loss += loss_fn(logits, y)*len(x)
            acc += acc_fn(logits, y) * len(x)
    print("epoch: {}, loss_test: {:7.5}, acc_test: {:5.2%}".format(
        i,
        loss.data.item()/len(test_loader.dataset),
        acc.data.item()/len(test_loader.dataset)
        ))


torch.save(net.state_dict(), "LeNet.pth")

