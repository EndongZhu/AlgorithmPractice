class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        ver1 = version1.split('.')
        ver2 = version2.split('.')
        length = max(len(ver1), len(ver2))
        for i in range(length):
            a = 0
            if i < len(ver1):
                a = int(ver1[i])
            b = 0
            if i < len(ver2):
                b = int(ver2[i])
            if a > b:
                return 1
            if a < b:
                return -1
        return 0
