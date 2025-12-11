#include <iostream>  // Äë˙ ââîäŕ-âűâîäŕ
#include <iomanip>   // Äë˙ ôîđěŕňčđîâŕíč˙ âűâîäŕ
using namespace std;
// Ôóíęöč˙ äë˙ âű÷čńëĺíč˙ ďëîůŕäč ęđóăŕ
double calculateCircleArea(double r) {
    // Îďđĺäĺë˙ĺě ęîíńňŕíňó ? ń âűńîęîé ňî÷íîńňüţ
    const double PI = 3.14159265358979323846;
    // Ôîđěóëŕ: S = ? * r?
    return PI * r * r;
}
int main() {
    // Íŕńňđîéęŕ âűâîäŕ äë˙ ďîääĺđćęč ęčđčëëčöű
    setlocale(0, "");
    // Ââîä ďîëüçîâŕňĺë˙
    double r;
    cout << "Ââĺäčňĺ đŕäčóń ęđóăŕ: ";
    cin >> r;
     // Ĺńëč ââĺäĺííîĺ ÷čńëî îňđčöŕňĺëüíîĺ
    if (r < 0) {
        cout << "Îřčáęŕ! Đŕäčóń íĺ ěîćĺň áűňü îňđčöŕňĺëüíűě!" << endl;
    }
    // Â îńňŕëüíűő ńëó÷ŕ˙ő
    else {
        double area = calculateCircleArea(r);

        // Âűâîäčě đĺçóëüňŕň (fixed č setprecision(2) îńňŕâë˙ţň 2 çíŕęŕ ďîńëĺ çŕď˙ňîé)
        cout << fixed << setprecision(2);
        cout << "Ďëîůŕäü ęđóăŕ = " << area << endl;
    }
    cout << fixed << setprecision(2);
    cout << "Ňĺńňîâűĺ çíŕ÷ĺíč˙: " << endl;

    //Ňĺńňčđîâŕíčĺ
    cout << "Đŕäčóń = 4: Ďëîůŕäü = " << calculateCircleArea(4) << endl;
    cout << "Đŕäčóń = 7: Ďëîůŕäü = " << calculateCircleArea(7) << endl;
    cout << "Đŕäčóń = 11: Ďëîůŕäü = " << calculateCircleArea(11) << endl;
    return 0;
}
