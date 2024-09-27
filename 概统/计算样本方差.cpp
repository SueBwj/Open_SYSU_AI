#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double calculateSampleVariance(const std::vector<double> &data)
{
    // ����������ֵ
    double mean = 0.0;
    for (double value : data)
    {
        mean += value;
    }
    mean /= data.size();
    std::cout << "������ֵ: " << mean << std::endl;
    // ������������
    double variance = 0.0;
    for (double value : data)
    {
        variance += pow(value - mean, 2);
    }
    variance /= (data.size() - 1); // ʹ�� (n-1) ��Ϊ��ĸ������ n ��������С

    return variance;
}

int main()
{
    // ���ļ�
    std::ifstream inputFile("sample_data.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "�޷����ļ�" << std::endl;
        return 1;
    }

    // ���ļ���ȡ����
    std::vector<double> data;
    double value;

    while (inputFile >> value)
    {
        data.push_back(value);
    }

    // �ر��ļ�
    inputFile.close();

    // ����Ƿ�ɹ���ȡ����
    if (data.empty())
    {
        std::cerr << "�ļ���û����Ч����" << std::endl;
        return 1;
    }

    // ���㲢�����������
    double sampleVariance = calculateSampleVariance(data);
    std::cout << "��������: " << sampleVariance << std::endl;

    return 0;
}